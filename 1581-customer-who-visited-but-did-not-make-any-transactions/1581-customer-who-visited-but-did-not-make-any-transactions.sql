# Write your MySQL query statement below
select customer_id, count(v.visit_id) as count_no_trans
from visits v
left join transactions t
on t.visit_id = v.visit_id
where
transaction_id is null
group by customer_id