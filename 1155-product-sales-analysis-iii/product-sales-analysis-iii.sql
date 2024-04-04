/* Write your T-SQL query statement below */
with cte as(
 select product_id,MIN(year) as minyear from sales group by product_id 
)select sales.product_id , sales.year as first_year  , sales.quantity , sales.price 
from sales
inner join cte
on cte.product_id=sales.product_id and sales.year=cte.minyear


