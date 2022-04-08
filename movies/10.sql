SELECT DISTINCT name FROM people, directors, ratings
 WHERE people.id = directors.person_id
   AND ratings.movie_id = directors.movie_id
   AND rating >= 9.0
   ORDER BY name ASC;