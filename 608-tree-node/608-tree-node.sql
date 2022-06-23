# Write your MySQL query statement below
SELECT id, 'Root' AS Type
from tree where p_id is null

UNION

select id, 'Leaf' as Type
from tree where id
NOT IN(
    select distinct p_id from tree where p_id is not null
)
and p_id is NOT NULL

UNION

SELECT id, 'Inner' as type from tree
where id IN(
    select distinct p_id from tree where p_id is not null
)
and p_id is NOT NULL
order by id;