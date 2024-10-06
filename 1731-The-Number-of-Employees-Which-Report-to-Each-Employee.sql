# Write your MySQL query statement below
SELECT y.employee_id, y.name, COUNT(x.reports_to) AS reports_count, ROUND(AVG(x.age)) AS average_age
FROM Employees x, Employees y
WHERE y.employee_id = x.reports_to
GROUP BY x.reports_to
ORDER BY y.employee_id;