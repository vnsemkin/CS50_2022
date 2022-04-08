SELECT name FROM people
 WHERE people.id IN (SELECT person_id FROM stars
 WHERE  movie_id IN (SELECT movie_id FROM stars, people
 WHERE people.id = stars.person_id
   AND people.name = "Kevin Bacon"
   AND people.birth = 1958))
   AND name != "Kevin Bacon";