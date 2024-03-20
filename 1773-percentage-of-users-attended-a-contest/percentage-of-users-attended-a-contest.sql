DECLARE @total_users float;
SELECT @total_users = COUNT(*) FROM Users;

SELECT r.contest_id, ROUND((COUNT(u.user_id) / @total_users) * 100, 2) as percentage
FROM Users u 
JOIN Register r ON u.user_id = r.user_id 
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;
