SELECT 
    p1.product_id AS product1_id, 
    p2.product_id AS product2_id, 
    info1.category AS product1_category, 
    info2.category AS product2_category, 
    COUNT(DISTINCT p1.user_id) AS customer_count
FROM 
    ProductPurchases p1
-- 1. Perform all your joins first
INNER JOIN 
    ProductPurchases p2 ON p1.user_id = p2.user_id 
LEFT JOIN 
    ProductInfo info1 ON p1.product_id = info1.product_id
LEFT JOIN 
    ProductInfo info2 ON p2.product_id = info2.product_id
-- 2. Apply the row-level filters next
WHERE 
    p1.product_id < p2.product_id
-- 3. Group and aggregate final results
GROUP BY 
    p1.product_id, 
    p2.product_id, 
    info1.category, 
    info2.category
HAVING 
    COUNT(DISTINCT p1.user_id) >= 3
ORDER BY 
    customer_count DESC, 
    product1_id ASC, 
    product2_id ASC;