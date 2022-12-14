# Write your MySQL query statement below
select distinct MAX(salary) as SecondHighestSalary from Employee e1
where salary < (
           select MAX(distinct salary) 
           from Employee e2 
           where e2.salary > e1.salary
          )