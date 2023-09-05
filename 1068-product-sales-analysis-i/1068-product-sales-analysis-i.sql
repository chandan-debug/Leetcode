# Write your MySQL query statement below
SELECT s.year,s.price,p.product_name
FROM Sales as s
LEFT JOIN product as p
ON s.Product_id=p.product_id
