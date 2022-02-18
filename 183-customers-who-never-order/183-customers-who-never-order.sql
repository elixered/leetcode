# Write your MySQL query statement below
select name as Customers from Customers as c
LEFT JOIN Orders as o
on o.customerId = c.id
where o.customerId is NULL;
