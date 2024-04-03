with cte as 
    (
    select customer_id, min(order_date) as first_order_date 
    from Delivery a 
    group by customer_id
    )
select 
round(SUM(case when d.order_date =d.customer_pref_delivery_date then 1 else 0 end )*100.0/COUNT(*),2) as immediate_percentage 
from Delivery   d 
join cte        c 
on d.customer_id=c.customer_id and d.order_date=c.first_order_date 
-- where d.order_date =d.customer_pref_delivery_date