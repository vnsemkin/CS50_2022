-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Read police report.
SELECT description FROM crime_scene_reports WHERE
    year = 2021
    AND day = 28
    AND month = 7
    AND street LIKE "%Humphrey%";
-- Read decription of witnesses.
SELECT transcript FROM interviews
 WHERE year = 2021
   AND day = 28
   AND month = 7
   AND transcript LIKE "%bakery%";
-- Check who is exit from bakery after 10:15.
SELECT license_plate FROM bakery_security_logs
 WHERE year = 2021
   AND day = 28
   AND month = 7
   AND hour = 10
   AND minute BETWEEN 15 AND 20
   AND activity = "exit";
-- Find owners of licence plates
SELECT *
  FROM people
 WHERE license_plate = "5P2BI95"
    OR license_plate = "94KL13X"
    OR license_plate = "6P58WS2"
    OR license_plate = "4328GD8"
    OR license_plate = "G412CB7";
-- Find call on 28 of July where duration less than 1 minutes.
SELECT * FROM "phone_calls"
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND duration <= 60;
-- Match caller and reciver numbers
SELECT * FROM "people" WHERE
phone_number LIKE  "%(996) 555-8899%"
OR phone_number LIKE "%(375) 555-8161%";
-- Check first flight from destinaiton
SELECT * FROM "flights"
WHERE year = 2021
  AND month = 7
  AND day = 29
  AND hour = 8;
-- Check passengers on this flight
SELECT * FROM "passengers" WHERE flight_id = 36;