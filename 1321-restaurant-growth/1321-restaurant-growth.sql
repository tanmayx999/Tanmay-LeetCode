WITH DailyTotals AS (
    -- Step 1: Sum up the amounts for each unique day
    SELECT 
        visited_on, 
        SUM(amount) AS day_amount
    FROM Customer
    GROUP BY visited_on
),
RollingStats AS (
    -- Step 2: Calculate 7-day moving sum and average using window functions
    SELECT 
        visited_on,
        SUM(day_amount) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS total_amount,
        ROUND(AVG(day_amount) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ), 2) AS average_amount,
        -- Generate a row number to easily filter out the first 6 records
        ROW_NUMBER() OVER (ORDER BY visited_on) AS rn
    FROM DailyTotals
)
-- Step 3: Fetch results starting only from the 7th day onward
SELECT 
    visited_on, 
    total_amount AS amount, 
    average_amount
FROM RollingStats
WHERE rn >= 7
ORDER BY visited_on;
