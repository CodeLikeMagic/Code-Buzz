# Write your MySQL query statement below

select s.user_id,
case when  c.action is null then 0.00
else round((sum(c.action = 'confirmed')/count(c.action)),2)
end as confirmation_rate
from Signups s
left join Confirmations c
on
s.user_id = c.user_id
group by s.user_id;