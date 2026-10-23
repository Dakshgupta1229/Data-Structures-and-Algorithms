# Write your MySQL query statement below
SELECT b.unique_id,a.name
FROM EmployeeUNI AS b
RIGHT JOIN Employees as a
ON b.id = a.id;