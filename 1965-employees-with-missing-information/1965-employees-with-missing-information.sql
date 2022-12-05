# Write your MySQL query statement below
select employee_id from Employees 
where employee_id not in(select employee_id from Salaries)
union
select employee_id from Salaries 
where employee_id not in(select employee_id from Employees)
order by employee_id;



/*
select e.employee_id from Employees e
left join Salaries s on 
e.employee_id = s.employee_id
where s.salary is NULL
union
select s.employee_id from Salaries s
left join Employees e on 
s.employee_id = e.employee_id
where e.name is NULL
order by employee_id;
*/