SELECT title FROM movies, ratings, stars, people
 WHERE ratings.movie_id = movies.id
   AND stars.movie_id = movies.id
   AND people.id = stars.person_id
   AND people.name LIKE "%Chadwick Boseman%"
   ORDER BY rating DESC
   LIMIT 5;
