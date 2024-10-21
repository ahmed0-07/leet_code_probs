# Write your MySQL query statement below
SELECT y.name
FROM Employee x JOIN Employee y
ON x.managerId = y.id
GROUP BY x.managerId
HAVING COUNT(*) >= 5;