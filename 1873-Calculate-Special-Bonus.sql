# Write your MySQL query statement below
SELECT employee_id, 
CASE
    WHEN employee_id % 2 = 1 AND name NOT LIKE 'M%' THEN salary
    else 0
END AS bonus
FROM Employees
ORDER BY employee_id;












#SELECT employee_id, salary AS bonus
#FROM Employees
#WHERE employee_id % 2 != 0 AND LEFT(name, 1) <> 'M'
#UNION
#SELECT employee_id, 0 AS bonus
#FROM Employees
#WHERE employee_id % 2 = 0 || LEFT(name, 1) = 'M'
#ORDER BY employee_id;
