/* Write your T-SQL query statement below */
select d.name Department  , e.name Employee ,salary Salary 
from employee e
join department d
on e.departmentId =d.id
where salary = 
(select max(salary) from employee t where t.departmentId =e.departmentId )
