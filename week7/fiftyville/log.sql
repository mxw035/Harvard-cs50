-- Keep a log of any SQL queries you execute as you solve the mystery.
-- to see all the tables and info
.schema
-- to check for crimes on the day of the crime july 28, 2020
SELECT description FROM crime_scene_reports WHERE year = '2020' AND month = 'July' AND day = '28';
-- turned in no results will try with just month and year
SELECT description FROM crime_scene_reports WHERE year = '2020' AND month = 'July';
-- no results try with id instead
SELECT id FROM crime_scene_reports WHERE year = 2020 AND month = 'July';
-- month needs to be an int
SELECT id FROM crime_scene_reports WHERE year = 2020 AND month = 7;
-- works add in the day
SELECT id FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28;
-- gives answer 293, 294, 295, 296, 297
-- get the details of each crime
SELECT description FROM crime_scene_reports WHERE id = 293;
SELECT description FROM crime_scene_reports WHERE id = 294;
SELECT description FROM crime_scene_reports WHERE id = 295;
-- 295 is the missing duck situation but i still want to check the rest
SELECT description FROM crime_scene_reports WHERE id = 295;
SELECT description FROM crime_scene_reports WHERE id = 296;
SELECT description FROM crime_scene_reports WHERE id = 297;
-- check the courthouse_search_logs for witnesses
SELECT id FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28;
-- prints id 219 - 292
-- prints out details of all crimes from that day
SELECT * FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28;
-- tyr to get court house info from this crime
SELECT * FROM courthouse_security_logs WHERE id = 295;
-- gave info 295 = 2020/7/29 0822, entrance and license plate IH61G08
-- I dont believe this was the right case-
-- gave information regaurding who entered and left the courthouse on 7/28
SELECT * FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28;
-- check all cars in and out hx
SELECT * FROM courthouse_security_logs WHERE license_plate = 'R3G7486';
SELECT * FROM courthouse_security_logs WHERE license_plate = '13FNH73';
SELECT * FROM courthouse_security_logs WHERE license_plate = '5P2BI95';
SELECT * FROM courthouse_security_logs WHERE license_plate = '94KL13X';
SELECT * FROM courthouse_security_logs WHERE license_plate = '6P58WS2';
SELECT * FROM courthouse_security_logs WHERE license_plate = '4328GD8';
SELECT * FROM courthouse_security_logs WHERE license_plate = 'G412CB7';
SELECT * FROM courthouse_security_logs WHERE license_plate = 'L93J712';
SELECT * FROM courthouse_security_logs WHERE license_plate = '322W7JE';
SELECT * FROM courthouse_security_logs WHERE license_plate = '0NTHK55';

-- check the interviews
SELECT * FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;
-- Ruth Eugene and Raymond where all very helpful

-- look at atm on fifer street earlier that day
SELECT * FROM atm_transactions WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location Like '%Fifer%';
-- look up bank accounts and get names
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id AND people.id WHERE account_number = 28500762;
-- names associated with this account whos license plate indicate they were in the courthouse at the time
-- patrick, amber, roger, evelyn, ernest, sphoia, danielle
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id AND people.id WHERE account_number = 28296815;
-- both of these give mulitple people to the same account number and person id, trying a different route

-- look up people by license plate who were at the court house
SELECT * FROM people WHERE license_plate = 'R3G7486';
-- Brandon
SELECT * FROM people WHERE license_plate = '13FNH73';
--sophia
SELECT * FROM people WHERE license_plate = '5P2BI95';
--patrick
SELECT * FROM people WHERE license_plate = '94KL13X';
--Ernest
SELECT * FROM people WHERE license_plate = 'G412CB7';
-- roger
SELECT * FROM people WHERE license_plate = 'L93JTIZ';
--Elizabeth
SELECT * FROM people WHERE license_plate = '322W7JE';
-- Russell
SELECT * FROM people WHERE license_plate = '0NTHK55';
--Evelynn
SELECT * FROM people WHERE license_plate = '6P58WS2';
--amber
SELECT * FROM people WHERE license_plate = '4328GD8';
--Danielle

-- Check passports with flights?
--find flight
SELECT * FROM flights WHERE year = 2020 AND month = 7 AND day =29;
-- found flight first leaving is id 36
SELECT full_name FROM airports WHERE id = 8;
--airport id 8 = fiftyville airport 36 departs from here and goes to id 4
SELECT full_name FROM airports WHERE id = 4;
-- Heathrow airport
-- shows info on passengers boarding flight 36
SELECT * FROM passengers WHERE flight_id = 36;
-- evelyn roger and ernest all on flight 36

--check into atm withdraws
-- get ids
SELECT id FROM people WHERE passport_number = 8294398571;
SELECT id FROM people WHERE passport_number = 1695452385;
SELECT id FROM people WHERE passport_number = 5773159633;

-- bank
-- double check phone number to use to track bank transactions
SELECT * FROM people WHERE id = 560886;
SELECT * FROM people WHERE id = 398010;
SELECT * FROM people WHERE id = 686048;
-- check bank
SELECT * FROM bank_accounts WHERE account_number = 28500762;
SELECT * FROM people WHERE id = 467400;
-- 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8 *** wd 48
SELECT * FROM bank_accounts WHERE account_number = 28296815;
SELECT * FROM people WHERE id = 395717;
--395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
SELECT * FROM bank_accounts WHERE account_number = 76054385;
SELECT * FROM people WHERE id = 449774;
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
SELECT * FROM bank_accounts WHERE account_number = 49610011;
SELECT * FROM people WHERE id = 686048;
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X **** wd 50$
SELECT * FROM bank_accounts WHERE account_number = 16153065;
SELECT * FROM people WHERE id = 458378;
-- 458378 | Roy | (122) 555-4581 | 4408372428 | QX4YZN3
SELECT * FROM bank_accounts WHERE account_number = 25506511;
SELECT * FROM people WHERE id = 396669;
--396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ *** wd 20
SELECT * FROM bank_accounts WHERE account_number = 81061156;
SELECT * FROM people WHERE id = 438727;
--438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0
SELECT * FROM bank_accounts WHERE account_number = 26013199;
SELECT * FROM people WHERE id = 514354;
--514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE *** ed 35
SELECT * FROM bank_accounts WHERE account_number = 86363979;
SELECT * FROM people WHERE id = 948985;
--948985 | Robert | (098) 555-1164 | 8304650265 | I449449

-- 4 people who withdrew money and where also at the court house were Danielle, Ernest, Elizabeth and Russel
-- 3 poeple on plane were  Robert, Elizabeth and Ernest

-- recheck flight
SELECT * FROM flights WHERE id = 36;
--36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
SELECT * FROM passengers WHERE flight_id = 36;
--recheck people on flight via passport
-- orgin
SELECT * FROM airports WHERE id = 8;
--8 | CSF | Fiftyville Regional Airport | Fiftyville
-- dest
SELECT * FROM airports WHERE id = 4;
--4 | LHR | Heathrow Airport | London

SELECT * FROM people WHERE passport_number = 7214083635;
--953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04
SELECT * FROM people WHERE passport_number = 1695452385;
--398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
SELECT * FROM people WHERE passport_number = 5773159633;
--686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
SELECT * FROM people WHERE passport_number = 1540955065;
--651714 | Edward | (328) 555-1152 | 1540955065 | 130LD9Z
SELECT * FROM people WHERE passport_number = 8294398571;
--560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
SELECT * FROM people WHERE passport_number = 1988161715;
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
SELECT * FROM people WHERE passport_number = 9878712108;
--395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN

--recheck courthouse log with flight license plate
SELECT * FROM courthouse_security_logs WHERE license_plate = 'M51FA04';
--Doris came and left on 7/30 1255 - 1807 was also on the flight 36 how did she get to london and back when left on 29
-- check all flights
SELECT * FROM passengers WHERE passport_number = 7214083635;
--36 | 7214083635 | 2A
--no evidence she came back
--does some one else share her vehicle?
SELECT name FROM people WHERE license_plate = 'M51FA04';
--Doris; doesnt appear so

-- check rest license plates
SELECT * FROM courthouse_security_logs WHERE license_plate = 'G412CB7';
--roger at courthouse from 0928 - 1020
SELECT * FROM courthouse_security_logs WHERE license_plate = '94KL13X';
--ernest at ch from 0823-1018
SELECT * FROM courthouse_security_logs WHERE license_plate = '130LD9Z';
--edward at courthouse on 25 and 30th
SELECT * FROM courthouse_security_logs WHERE license_plate = '0NTHK55';
-- evelyn at ch from 0842-1023
SELECT * FROM courthouse_security_logs WHERE license_plate = '1106N58';
-- Madison at CH from 0834-1035
SELECT * FROM courthouse_security_logs WHERE license_plate = '30G67EN';
--bobby was only there on the 26th and 30

-- rule out edward and bobby
-- possible suspect roger, ernest evelyn and madison
-- compare to previous atm results ernest took out 50$,
--check to see others atm activity
-- roger activity no bank account number
-- ernest
SELECT * FROM bank_accounts WHERE person_id = 686048;
SELECT * FROM atm_transactions WHERE account_number = 49610011;
-- ernest made withdraws on 7/26 for 10 and 7/28 for 50
SELECT * FROM bank_accounts WHERE person_id = 560886;
--evelyn has no account number
--get madisson account number
SELECT * FROM bank_accounts WHERE person_id = 449774;
-- check transactions
SELECT * FROM atm_transactions WHERE account_number = 76054385;
--withdraw from fifer on 7/28 fpr 60
--check phone calls
SELECT * FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration <=60;
--check phone numbers
SELECT * FROM people WHERE phone_number = '(130) 555-0289'; -- roger
SELECT * FROM people WHERE phone_number = '(996) 555-8899'; --jack
SELECT * FROM people WHERE phone_number = '(499) 555-9472'; --evelyn
SELECT * FROM people WHERE phone_number = '(892) 555-8872'; --larry
SELECT * FROM people WHERE phone_number = '(367) 555-5533'; -- Ernest
SELECT * FROM people WHERE phone_number = '(375) 555-8161'; --Berthold
SELECT * FROM people WHERE phone_number = '(609) 555-5876'; --Kathryn
SELECT * FROM people WHERE phone_number = '(389) 555-5198'; --Danielle
SELECT * FROM people WHERE phone_number = '(499) 555-9472'; --Evelyn
SELECT * FROM people WHERE phone_number = '(717) 555-1342'; --Melisa
SELECT * FROM people WHERE phone_number = '(286) 555-6063';-- madison
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
SELECT * FROM people WHERE phone_number = '(676) 555-6554'; --james
--250277 | James | (676) 555-6554 | 2438825627 | Q13SVG6
SELECT * FROM people WHERE phone_number = '(770) 555-1861'; --Russell
SELECT * FROM people WHERE phone_number = '(725) 555-3243'; --phillip
SELECT * FROM people WHERE phone_number = '(031) 555-6622'; -- kimberly
SELECT * FROM people WHERE phone_number = '(910) 555-3251'; --jacqueline
SELECT * FROM people WHERE phone_number = '(826) 555-1652'; -- bobby
SELECT * FROM people WHERE phone_number = '(066) 555-9701'; -- dorris
SELECT * FROM people WHERE phone_number = '(338) 555-6650'; -- victoria
SELECT * FROM people WHERE phone_number = '(704) 555-2131'; -- anna

--check out other people from calls
SELECT * FROM people WHERE name = 'Jack';
--567218 | Jack | (996) 555-8899 | 9029462229 | 52R0Y8U
SELECT * FROM courthouse_security_logs WHERE license_plate = '52R0Y8U';
--not in courthouse

SELECT * FROM people WHERE name = 'Larry';
--251693 | Larry | (892) 555-8872 | 2312901747 | O268ZZ0
SELECT * FROM courthouse_security_logs WHERE license_plate = 'O268ZZ0';
--not at court house

SELECT * FROM people WHERE name = 'Berthold';
--864400 | Berthold | (375) 555-8161 |  | 4V16VO0
SELECT * FROM courthouse_security_logs WHERE license_plate = '4V16VO0';
--248 | 2020 | 7 | 28 | 8 | 50 | entrance | 4V16VO0
--249 | 2020 | 7 | 28 | 8 | 50 | exit | 4V16VO0

SELECT * FROM people WHERE name = 'Kathryn';
--561160 | Kathryn | (609) 555-5876 | 6121106406 | 4ZY7I8T
SELECT * FROM courthouse_security_logs WHERE license_plate = '4ZY7I8T';
--at ch on 30 and 31

SELECT * FROM people WHERE name = 'Melissa';
--626361 | Melissa | (717) 555-1342 | 7834357192 |
-- no license plate

SELECT * FROM people WHERE name = 'James';
SELECT * FROM courthouse_security_logs WHERE license_plate = 'Q13SVG6';
-- at ch on 25 and 29

SELECT * FROM courthouse_security_logs WHERE license_plate = 'GW362R6'; --phillip
-- at ch on 29

SELECT * FROM courthouse_security_logs WHERE license_plate = 'Q12B3Z3'; --kimberly
--not at ch

SELECT * FROM courthouse_security_logs WHERE license_plate = '43V0R5D'; --jacqueline
-- at ch on 30
