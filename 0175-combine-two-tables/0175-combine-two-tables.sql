# Write your MySQL query statement below

SELECT Person.firstName,Person.lastName,address.city,address.state from Person left outer join
address  on Person.personId=address.personId;
