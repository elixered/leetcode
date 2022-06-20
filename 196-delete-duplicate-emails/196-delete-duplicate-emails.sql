DELETE p1 from Person p1,Person p2
where p1.email = p2.email and p1.Id > p2.Id;