/* Write your T-SQL query statement below */

select  FORMAT(trans_date,'yyyy-MM') as month,
        country,
        COUNT(*) as trans_count,
        COUNT(case when state ='approved' then 1 else null end) as approved_count,
        SUM(amount) as trans_total_amount,
        SUM(case when state='approved' then amount else 0 end) as approved_total_amount
from Transactions 
group by FORMAT(trans_date,'yyyy-MM'),country

       

   
