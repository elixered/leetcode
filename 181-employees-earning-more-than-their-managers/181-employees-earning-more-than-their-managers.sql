select E.name as Employee from Employee E
join Employee as M
on E.ManagerId = M.Id
where E.Salary > M.Salary;