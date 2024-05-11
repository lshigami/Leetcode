# Write your MySQL query statement below
WITH cte as(
SELECT distinct customer_id as customer_id
FROM Customer)
select cte.customer_id
from cte
where not exists (
    select product_key from product
    except
    select distinct product_key from customer where customer_id=cte.customer_id
)