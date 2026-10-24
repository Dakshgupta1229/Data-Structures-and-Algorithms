# Write your MySQL query statement below
SELECT x,y,z,CASE WHEN (x+y)>z AND x>=0 AND y>=0 AND x>=0 AND (y+z)>x AND (x+z)>y THEN "Yes" Else "No" END AS triangle
FROM Triangle;