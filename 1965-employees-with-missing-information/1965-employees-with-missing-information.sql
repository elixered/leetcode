# Write your MySQL query statement below
SELECT employee_id from Employees
where employee_id not in (Select employee_id from Salaries)
UNION
SELECT employee_id from Salaries
where employee_id not in (Select employee_id from Employees)
ORDER BY employee_id;