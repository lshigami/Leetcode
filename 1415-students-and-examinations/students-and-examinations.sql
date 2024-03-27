SELECT st.student_id,st.student_name,su.subject_name ,COUNT(ex.subject_name) as attended_exams 
FROM students st
CROSS JOIN subjects su
LEFT JOIN examinations ex
ON st.student_id=ex.student_id and su.subject_name=ex.subject_name
GROUP BY st.student_id,st.student_name,su.subject_name

order by st.student_id , su.subject_name