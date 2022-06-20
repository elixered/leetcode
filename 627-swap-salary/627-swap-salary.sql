# Write your MySQL query statement below
UPDATE Salary 
set sex = case sex
when 'm' then 'f'
else 'm'
end;