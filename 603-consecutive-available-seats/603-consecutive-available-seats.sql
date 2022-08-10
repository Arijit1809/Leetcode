# Write your MySQL query statement below
select distinct a.seat_id
from cinema a, cinema b
  where abs(a.seat_id - b.seat_id) = 1
  and a.free = true and b.free = true
order by a.seat_id
;