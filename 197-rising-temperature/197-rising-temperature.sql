# Write your MySQL query statement below
select weather.id from weather
join weather as w on w.recordDate = SUBDATE(weather.recordDate,1)
where weather.temperature > w.temperature;