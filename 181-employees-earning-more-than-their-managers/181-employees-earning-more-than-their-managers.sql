SELECT a.name as 'Employee' from Employee a
Join Employee b
on ((a.managerId = b.id) and (a.salary > b.salary));
