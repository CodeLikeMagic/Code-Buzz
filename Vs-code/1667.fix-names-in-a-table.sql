--
-- @lc app=leetcode id=1667 lang=mysql
--
-- [1667] Fix Names in a Table
--

-- @lc code=start
# Write your MySQL query statement below

-- @lc code=end
select user_id , 
concat(upper(substr(name,1,1)),lower(substr(name,2,50))) as name
from Users
order by user_id