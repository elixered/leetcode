# Write your MySQL query statement below
select distinct v1.author_id as id from
Views as v1 join views
where v1.author_id = v1.viewer_id
order by id asc
;