WITH MinDate AS (SELECT player_id, MIN(event_date) minDt
FROM Activity
GROUP BY player_id)
SELECT ROUND(COUNT(a.player_id)*1.0/(SELECT COUNT(DISTINCT player_id) FROM ACtivity),2) fraction  
FROM Activity a 
join MinDate md
on a.player_id = md.player_id
WHERE DATEDIFF(day, md.minDt, event_date) = 1
