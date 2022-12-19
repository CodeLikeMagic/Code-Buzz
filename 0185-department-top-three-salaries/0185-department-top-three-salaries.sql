# Write your MySQL query statement bel
select d.name as Department,
e1.name as Employee,
e1.salary 
from Employee e1
join Department d
on e1.departmentId = d.Id
where 3 > (
        select count(distinct(e2.salary))
        from Employee e2
        where e2.salary > e1.salary
        and e1.departmentId = e2.departmentId
            )
