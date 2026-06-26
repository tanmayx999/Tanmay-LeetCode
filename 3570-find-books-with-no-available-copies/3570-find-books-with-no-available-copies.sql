SELECT 
    l.book_id,
    l.title,
    l.author,
    l.genre,
    l.publication_year,
    COUNT(*) AS current_borrowers
FROM 
    borrowing_records b
JOIN 
    library_books l ON b.book_id = l.book_id
WHERE 
    b.return_date IS NULL
GROUP BY 
    l.book_id, 
    l.title, 
    l.author, 
    l.genre, 
    l.publication_year, 
    l.total_copies
HAVING 
    COUNT(*) = l.total_copies
ORDER BY 
    current_borrowers DESC, 
    l.title ASC;