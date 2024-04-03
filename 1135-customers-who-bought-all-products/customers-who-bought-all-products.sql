/* Write your T-SQL query statement below */
DECLARE @counter INT;
SELECT @counter = COUNT(* ) FROM product;

select customer_id 
from customer
group by customer_id
having count(distinct product_key) = @counter