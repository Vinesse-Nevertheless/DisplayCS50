SELECT title from ratings
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
JOIN movies ON movies.id = ratings.movie_id
WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;