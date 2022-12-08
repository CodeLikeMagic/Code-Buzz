# Write your MySQL query statement below
select score, dense_rank() over(order by score DESC) as "rank"
from scores

/*
The DENSE_RANK() is a window function that assigns a rank ,
to each row within a partition of a result set.
Unlike the RANK() function, the DENSE_RANK() function
returns consecutive rank values. 
Rows in each partition receive the same ranks if they have the same values.
*/