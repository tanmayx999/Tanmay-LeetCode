SELECT id,
    CASE
        -- Case - 1 ROOT p_id = null --
        WHEN p_id IS NULL THEN 'Root'

        -- CASE - 2 Leaf when id is not in p_id note - remove null --
        WHEN id NOT IN (SELECT P_id FROM Tree WHERE p_id IS NOT NULL) THEN 'Leaf'
        
        -- CASE - 3 Inner 
        ELSE 'Inner'

    END AS type
FROM Tree