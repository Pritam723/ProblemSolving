# Write your MySQL query statement below

WITH no_timeout_info AS(
    SELECT user_id, 'timeout' as action, 0 as req_count
    FROM(
        SELECT user_id FROM Signups
        EXCEPT
        SELECT DISTINCT user_id from Confirmations WHERE action = 'timeout'
    ) as T1
),
no_confirmation_info AS(
    SELECT user_id, 'confirmed' as action, 0 as req_count
    FROM(
        SELECT user_id FROM Signups
        EXCEPT
        SELECT DISTINCT user_id from Confirmations WHERE action = 'confirmed'
    ) as T1
),
all_req_info AS
(
    SELECT user_id,action, count(*) as req_count from Confirmations group by user_id,action
    UNION
    SELECT user_id,action, req_count FROM no_timeout_info
    UNION
    SELECT user_id,action, req_count FROM no_confirmation_info
),
total_req_info AS
(
    SELECT user_id, sum(req_count) as total_req FROM all_req_info group by user_id
),
confirmed_req_info AS
(
    SELECT user_id, sum(req_count) as confirmed_req FROM all_req_info WHERE action = 'confirmed' group by user_id
)

SELECT user_id,
    CASE 
        WHEN T1.total_req = 0 THEN 0.00
        ELSE round(T1.confirmed_req/T1.total_req,2)
        END as confirmation_rate
FROM(
    SELECT * FROM confirmed_req_info NATURAL JOIN total_req_info
) as T1