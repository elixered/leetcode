# Write your MySQL query statement below
SELECT employee_id,salary*(employee_id%2)*(name not like 'M%') as bonus
from employees
ORDER BY employee_id;