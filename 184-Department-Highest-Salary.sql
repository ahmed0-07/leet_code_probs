# Write your MySQL query statement below
SELECT Department, Employee, Salary
FROM
(
    SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary, dense_rank() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS \ro\
    FROM Employee e JOIN Department d
    ON e.departmentId = d.id
) AS table_n
WHERE ro = 1;