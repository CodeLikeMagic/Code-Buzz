# Write your MySQL query statement below
select
query_name,
ifnull(round(avg(rating/position),2),0) as quality,
ifnull(round(avg(if(rating<3,1,0))*100,2),0) as poor_query_percentage
from Queries
where query_name is not null
group by query_name;
