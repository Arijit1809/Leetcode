select 
    name
from
    employee as t1 
join 
(
    select 
        managerId 
    from 
        employee
    group by 
        managerId
    having count(managerId)>=5
) as t2
on t1.id = t2.managerId;