# Write your MySQL query statement below
select distinct p1.email from Person as p1
join Person as p2
on p1.id != p2.id and p1.email = p2.email;
