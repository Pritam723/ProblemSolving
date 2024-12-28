# Write your MySQL query statement below
WITH total_users AS
(
    SELECT count(DISTINCT user_id) as t_users
    FROM Users
),
contest_info AS
(
    SELECT contest_id, count(*) as users
    FROM Register
    GROUP BY contest_id
)

SELECT contest_id, round(users*100/t_users,2) as percentage FROM contest_info,total_users
ORDER BY percentage DESC, contest_id ASC