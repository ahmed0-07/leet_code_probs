# Write your MySQL query statement below
SELECT Person.firstName, Person.lastName, Address.city, Address.state
From Person LEFT join Address
ON person.personId = Address.personID;