# Write your MySQL query statement below
select distinct name from SalesPerson
where sales_id not in (
    select distinct a.sales_id from Orders a left join Company b on a.com_id = b.com_id
    where b.name = 'RED' )




/*
select s.name
from SalesPerson s
where s.name not in
    (select s.name
    from SalesPerson s
        left join Orders o on s.sales_id = o.sales_id
        left join Company c on o.com_id = c.com_id
    where c.name = 'Red')
*/   
    

