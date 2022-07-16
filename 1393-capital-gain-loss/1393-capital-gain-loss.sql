# Write your MySQL query statement below

SELECT stock_name , SUM(CASE WHEN operation = "Buy" THEN  -1*price ELSE price END) as capital_gain_loss
from Stocks
GROUP BY  stock_name;