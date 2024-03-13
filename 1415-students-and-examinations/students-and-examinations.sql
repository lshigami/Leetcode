SELECT 
    s.student_id,
    s.student_name,
    sj.subject_name,
    COUNT(e.student_id) as 'attended_exams'
FROM Students s CROSS JOIN Subjects sj

LEFT JOIN Examinations e
ON      s.student_id = e.student_id 
and sj.subject_name =e.subject_name 

GROUP BY s.student_id,s.student_name, sj.subject_name
ORDER BY s.student_id, sj.subject_name;

