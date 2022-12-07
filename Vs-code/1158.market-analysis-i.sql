--
-- @lc app=leetcode id=1158 lang=mysql
--
-- [1158] Market Analysis I
--

-- @lc code=start
# Write your MySQL query statement below
select users.user_id as buyer_id,
join_date,
IFNULL(count(order_id), 0) as orders_in_2019 
from users
left join orders
on users.user_id = buyer_id
and year(order_date) = '2019'
group by user_id;

##by using where records not having 2019 wont be joined at all 
##where order_date like "2019%"
-- @lc code=end

