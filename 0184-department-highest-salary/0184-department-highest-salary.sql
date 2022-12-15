# Write your MySQL query statement below

select Department.name as Department,
Employee.name as Employee,
salary as Salary
from Employee 
    join
Department
on Employee.departmentId = Department.id
where (Employee.departmentId, Salary) in (
        select departmentId, max(salary)
        from Employee
        group by departmentId
    )            
                
