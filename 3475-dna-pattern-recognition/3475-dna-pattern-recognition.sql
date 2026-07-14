SELECT 
    sample_id, 
    dna_sequence, 
    species,
    -- Starts with ATG
    (dna_sequence LIKE 'ATG%') AS has_start,
    -- Ends with TAA, TAG, or TGA ($ represents the end of the string)
    (dna_sequence REGEXP 'TAA$|TAG$|TGA$') AS has_stop,
    -- Contains ATAT anywhere
    (dna_sequence LIKE '%ATAT%') AS has_atat,
    -- Contains 3 or more consecutive Gs
    (dna_sequence REGEXP 'GGG') AS has_ggg
FROM 
    Samples
ORDER BY 
    sample_id ASC;