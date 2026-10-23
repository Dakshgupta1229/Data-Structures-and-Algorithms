# Write your MySQL query statement below
SELECT a.customer_id,COUNT(*) AS count_no_trans
FROM Visits a
LEFT JOIN Transactions t
ON a.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY a.customer_id;