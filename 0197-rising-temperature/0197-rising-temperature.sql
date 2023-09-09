# Write your MySQL query statement below
SELECT w1.id
FROM weather as w1
JOIN weather as  w2
ON datediff(w1.recorddate,w2.recorddate)=1
and w1.temperature>w2.temperature;