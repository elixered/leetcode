SELECT
    s.name
FROM
    salesperson s
WHERE
    s.sales_id NOT IN (SELECT
            o.sales_id
        FROM
            orders o
                Natural JOIN
            company c
        WHERE
            c.name = 'RED')