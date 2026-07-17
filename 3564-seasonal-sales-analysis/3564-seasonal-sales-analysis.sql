WITH SeasonalSales AS (
    -- Step 1: Join tables, define seasons, and calculate aggregates per category per season
    SELECT 
        CASE 
            WHEN MONTH(s.sale_date) IN (12, 1, 2) THEN 'Winter'
            WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring'
            WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer'
            ELSE 'Fall'
        END AS season,
        p.category,
        SUM(s.quantity) AS total_quantity,
        SUM(s.quantity * s.price) AS total_revenue
    FROM sales s
    JOIN products p ON s.product_id = p.product_id
    GROUP BY 1, p.category
),
RankedSales AS (
    -- Step 2: Rank the categories inside each season using the tie-breaker rules
    SELECT 
        season,
        category,
        total_quantity,
        total_revenue,
        ROW_NUMBER() OVER (
            PARTITION BY season 
            ORDER BY total_quantity DESC, total_revenue DESC, category ASC
        ) AS rnk
    FROM SeasonalSales
)
-- Step 3: Filter for the top-ranked category per season
SELECT 
    season,
    category,
    total_quantity,
    total_revenue
FROM RankedSales
WHERE rnk = 1
ORDER BY season ASC;