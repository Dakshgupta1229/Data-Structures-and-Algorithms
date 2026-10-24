# Write your MySQL query statement below
SELECT sell_date,COUNT(DISTINCT Product) as num_sold,GROUP_CONCAT(DISTINCT Product ORDER BY Product) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;