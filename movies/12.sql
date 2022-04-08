   SELECT title FROM movies, stars, people
    WHERE movies.id = stars.movie_id
      AND people.id = stars.person_id
      AND name LIKE "%Johnny Depp%"
INTERSECT
   SELECT title FROM movies, stars, people
    WHERE movies.id = stars.movie_id
      AND people.id = stars.person_id
      AND name LIKE "%Helena Bonham Carter%";