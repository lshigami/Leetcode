-- /* Write your T-SQL query statement below */
-- select (
--             case when e.name is null then s.employee_id
--                 when s.salary is null then e.employee_id 
--                 end
--         ) as employee_id 
-- from employees e
-- full join salaries s
-- on s.employee_id=e.employee_id
-- where name is null or salary is null
-- order by case when e.name is null then s.employee_id
--                 when s.salary is null then e.employee_id 
--                 end

select employee_id from employees where employee_id NOT IN
(select employee_id from salaries)
UNION
select employee_id from salaries where employee_id NOT IN
(select employee_id from Employees )
order by employee_id