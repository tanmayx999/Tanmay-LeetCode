SELECT
    CASE 
        -- Case 1 last odd row --
        WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN id

        -- Case 2 remaning odd 
        WHEN id % 2 = 1 THEN id + 1

        ELSE id - 1
    END AS id, student
FROM Seat
ORDER BY id ASC