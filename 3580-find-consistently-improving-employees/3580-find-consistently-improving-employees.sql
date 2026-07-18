WITH RankedReviews AS (
    SELECT 
        employee_id,
        rating,
        -- Rank reviews by date starting from the most recent (1 = latest, 2 = second latest, 3 = third latest)
        ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) as rn,
        -- Fetch the rating of the next most recent review (e.g., if we are at rn=1, lead fetching rn=2)
        LEAD(rating, 1) OVER (PARTITION BY employee_id ORDER BY review_date DESC) as prev_rating,
        -- Fetch the rating of the review before that (e.g., if we are at rn=1, lead fetching rn=3)
        LEAD(rating, 2) OVER (PARTITION BY employee_id ORDER BY review_date DESC) as oldest_rating
    FROM performance_reviews
)
SELECT 
    e.employee_id,
    e.name,
    -- Latest rating (rn=1) minus earliest rating among the last 3 (rn=3)
    (r.rating - r.oldest_rating) AS improvement_score
FROM RankedReviews r
JOIN employees e ON r.employee_id = e.employee_id
WHERE r.rn = 1                  -- Focus on the latest review row per employee
  AND r.oldest_rating IS NOT NULL -- Ensures the employee has at least 3 reviews
  AND r.rating > r.prev_rating   -- Latest rating (rn=1) is strictly greater than second latest (rn=2)
  AND r.prev_rating > r.oldest_rating -- Second latest (rn=2) is strictly greater than third latest (rn=3)
ORDER BY improvement_score DESC, e.name ASC;