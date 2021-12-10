SELECT title FROM people
JOIN movies ON movies.id = stars.movie_id
JOIN stars ON stars.person_id = people.id
WHERE name = "Johnny Depp"
AND title IN (
SELECT title FROM people
JOIN movies on movies.id = stars.movie_id
JOIN stars on stars.person_id = people.id
WHERE name = "Helena Bonham Carter");