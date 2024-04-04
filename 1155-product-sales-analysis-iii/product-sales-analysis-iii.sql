WITH cte AS (
    SELECT product_id, MIN(year) AS minyear 
    FROM sales 
    GROUP BY product_id 
)
SELECT s.product_id, s.year AS first_year, s.quantity, s.price 
FROM sales s
INNER JOIN cte ON cte.product_id = s.product_id 
              AND s.year = cte.minyear;
