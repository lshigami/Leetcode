/* Write your T-SQL query statement below */
select coalesce ((
  select top 1 num from mynumbers
  group by num
  having count(*) = 1
  order by num desc
), null) as num;