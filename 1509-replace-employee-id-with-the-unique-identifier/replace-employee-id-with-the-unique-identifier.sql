# Write your MySQL query statement below
select e2.unique_id as unique_id , e1.name as name from Employees as e1 Left Join EmployeeUNI as e2 on e1.id = e2.id;