/*xem code cc- ishigami*/
select firstname,lastname,city,state
from person
left join address
on person.personId=address.personId
