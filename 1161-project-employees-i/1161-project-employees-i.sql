# Write your MySQL query statement below
SELECT project_id, round(avg(E.experience_years),2) as average_years
FROM Project P NATURAL JOIN Employee E
GROUP BY P.project_id