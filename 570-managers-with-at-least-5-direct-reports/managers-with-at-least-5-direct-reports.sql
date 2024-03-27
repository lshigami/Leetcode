select name from employee
where id in (
Select  managerID as id
from employee
group by managerID
having count(*) >= 5)