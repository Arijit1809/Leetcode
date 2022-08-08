select c.name as customers 
from customers c
where c.id not in 
(
    select customerId as id
    from orders
)