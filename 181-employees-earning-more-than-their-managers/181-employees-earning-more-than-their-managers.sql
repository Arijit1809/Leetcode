# Write your MySQL query statement below
select e1.name as employee 
from employee as e1 left join employee as e2
on e1.managerId = e2.id
where e1.salary > e2.salary