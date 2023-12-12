# Write your MySQL query statement below
delete t2 from Person t2
inner join Person t1
where
    t1.id < t2.id
    and
    t1.email = t2.email;