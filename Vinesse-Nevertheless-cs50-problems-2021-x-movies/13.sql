SELECT DISTINCT (name) FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN (
    SELECT movies.id FROM movies
    JOIN stars on stars.movie_id = movies.id
    JOIN people on people.id = stars.person_id
    WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
AND people.name != "Kevin Bacon";