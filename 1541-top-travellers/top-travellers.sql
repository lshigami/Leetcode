/* Write your T-SQL query statement below */
select name,SUM(case when distance is null then 0 else distance end) as travelled_distance 
from users 
left join rides
on users.id=rides.user_id
group by user_id,name
order by travelled_distance desc,name