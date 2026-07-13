WITH RankedScores AS (
    SELECT 
        student_id,
        subject,
        score,
        -- Find the first exam score
        FIRST_VALUE(score) OVER(
            PARTITION BY student_id, subject 
            ORDER BY exam_date ASC
        ) AS first_score,
        -- Find the latest exam score (forces the window to look at all dates)
        FIRST_VALUE(score) OVER(
            PARTITION BY student_id, subject 
            ORDER BY exam_date DESC
        ) AS latest_score,
        -- Count unique exam dates to satisfy the "at least two dates" rule
        COUNT(exam_date) OVER(
            PARTITION BY student_id, subject
        ) AS exam_count
    FROM Scores
)
SELECT DISTINCT 
    student_id, 
    subject, 
    first_score, 
    latest_score
FROM RankedScores
WHERE exam_count >= 2 AND latest_score > first_score
ORDER BY student_id, subject;