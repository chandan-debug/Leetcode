# Write your MySQL query statement below

SELECT p.firstName,p.lastName,q.city,q.state from Person as p left outer join
address as q on p.personId=q.personId;
