/* Write your T-SQL query statement below */
SELECT unique_id,name
FROM Employees
LEFT JOIN EmployeeUNI
ON EmployeeUNI.id=Employees.id