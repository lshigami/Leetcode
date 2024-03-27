SELECT a.machine_id, ROUND(1.0*SUM(b.timestamp -a.timestamp)/COUNT(a.process_id),3) as processing_time
FROM Activity a
INNER JOIN Activity b
ON a.machine_id=b.machine_id and a.process_id=b.process_id and a.activity_type='start' and b.activity_type='end'
GROUP BY a.machine_id