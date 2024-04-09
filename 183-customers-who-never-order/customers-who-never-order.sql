/* Write your T-SQL query statement below */
select name as Customers 
from customers
left join orders
on customers.id=orders.customerid
where orders.id is null