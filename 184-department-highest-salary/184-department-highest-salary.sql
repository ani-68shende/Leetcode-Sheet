# Write your MySQL query statement below
select Department.name as Department, Employee.name as Employee, Employee.Salary as Salary from
Employee , Department 
WHERE Employee.departmentId = Department.id 
and Salary = (Select max(Salary) from Employee where Employee.departmentId = Department.id);