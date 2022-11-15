# Write your MySQL query statement below
select Customers.customer_id, Customers.customer_name
from Customers, Orders
where Customers.customer_id = Orders.customer_id
group by Orders.customer_id
having sum(Orders.product_name='A')>0 and sum(Orders.product_name='B')>0 and sum(Orders.product_name='C')=0;