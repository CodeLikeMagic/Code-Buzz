# Write your MySQL query statement below - (a + b <= c || a + c <= b || b + c <= a)
select * ,
CASE
WHEN (x + y <= z || y + z <= x || z + x <= y) THEN "No"
ELSE "Yes"
END AS triangle
from triangle;