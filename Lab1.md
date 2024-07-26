** a. Write an SQL Query to find the year from date. ** <br>

```mySQL
  SELECT YEAR(CURDATE()) as year;
```
<img width="306" alt="Screenshot 2024-07-26 at 12 31 31 PM" src="https://github.com/user-attachments/assets/d1ee182a-124e-47d9-b88a-e16043e10b92"> <br>

** b. Check whether date passed to Query is the date of a given format or no ** <br>

```mySQL
  SELECT str_to_date('2024-07-18','%y-%m-%d') as valid_date;
```
<img width="725" alt="Screenshot 2024-07-26 at 12 48 30 PM" src="https://github.com/user-attachments/assets/b3092c09-4b95-4d2c-8644-dd8975d94334">
<br>

** c. Find the size of the SCHEMA/USER. ** <br>

```mySQL
  SELECT
   SUM(ROUND(((DATA_LENGTH + INDEX_LENGTH) / 1024 / 1024), 2)) AS "SIZE IN MB"
   FROM INFORMATION_SCHEMA.TABLES
   WHERE TABLE_SCHEMA = "SCHEMA-NAME";
```
<img width="635" alt="Screenshot 2024-07-26 at 12 56 08 PM" src="https://github.com/user-attachments/assets/6f82753a-6819-46e5-b342-74e850247030">
<br>

** d. Display the current time. ** <br>

```mySQL
  SELECT NOW();
```
<img width="216" alt="Screenshot 2024-07-26 at 1 01 10 PM" src="https://github.com/user-attachments/assets/4e582d4b-2387-4ed2-92ec-99ea761aa086">
<br>

** e. Given a date, retrive the next day's date. ** <br>

```mySQL
  SELECT DATE_ADD("2024-07-18", INTERVAL 1 DAY);
```
<img width="493" alt="Screenshot 2024-07-26 at 1 02 42 PM" src="https://github.com/user-attachments/assets/70c569bd-c75d-492a-b759-d12bd0ae25a4">
<br>

** f. Get the database's date ** <br>

```mySQL
  SELECT CURRENT_TIMESTAMP;
```
<img width="241" alt="Screenshot 2024-07-26 at 1 04 36 PM" src="https://github.com/user-attachments/assets/09e350d5-e17d-4584-bf71-ff3b36111eb5">
<br>

** g. Return the deafult databse name ** <br>

```mySQL
  SELECT CURRENT_TIMESTAMP;
```
<img width="488" alt="Screenshot 2024-07-26 at 1 06 33 PM" src="https://github.com/user-attachments/assets/978e7eaa-cbf0-4cfc-8b71-68c11c0f190e">
<br>

** h. Retrive the current MYSQL user naema nd host name ** <br>

```mySQL
  SELECT USER() AS Username, @@hostname AS Hostname;
```
<img width="405" alt="Screenshot 2024-07-26 at 1 07 47 PM" src="https://github.com/user-attachments/assets/c63cc7ec-2afe-4bfe-9347-c6be925fcd09">
<br>

** i. Find the string that tells MYSQL server version ** <br>

```mySQL
  SELECT VERSION() as version;
```
<img width="256" alt="Screenshot 2024-07-26 at 1 10 31 PM" src="https://github.com/user-attachments/assets/5ea7e5e4-c919-46e7-abaa-d25b1d3b369c">
<br>

** j. Perform Bitwise OR, Bitwise XOR and Bitwise AND. ** <br>

```mySQL
  SELECT VERSION() as version;
```
<img width="511" alt="Screenshot 2024-07-26 at 1 15 52 PM" src="https://github.com/user-attachments/assets/d6a1e533-8fe1-4c2b-b97c-1ffb8eb90327">
<br>

** k. Find the difference between two dates and print in terms of the number of days. ** <br>

``` mySQL
  SELECT DATEDIFF("2017-06-25", "2017-06-15") AS diff_in_days;
```

<img width="479" alt="Screenshot 2024-07-26 at 1 17 14 PM" src="https://github.com/user-attachments/assets/a52c2bf4-e267-47eb-9695-a1bf96c7ad2e">
<br>

** l. Add one day to the current date. ** <br>

``` mySQL
   SELECT DATE_ADD('2024-07-26', INTERVAL 1 DAY) as next_day;
```

<img width="474" alt="Screenshot 2024-07-26 at 1 18 44 PM" src="https://github.com/user-attachments/assets/0dc422fb-161e-4134-96e9-7398201ffb26">
<br>

** m. Add two hours and 5000 minutes to the current date and print the new date. ** <br>

``` mySQL
   SELECT DATE_ADD(DATE_ADD(NOW(), INTERVAL 2 HOUR), INTERVAL 5000 MINUTE) AS New_Date;
```

<img width="675" alt="Screenshot 2024-07-26 at 1 20 56 PM" src="https://github.com/user-attachments/assets/931799ac-536c-43f0-a126-f9543f702c7f">
<br>

** n. Find the floor and ceil values of a floating point number. Also operate on the power, log,
modulus, round off and truncate functions. ** <br>

``` mySQL
   SELECT CEIL(4.2), FLOOR(4.2), POWER(2, 3), MOD(10, 3), ROUND(8.99, 0), TRUNCATE(8.99, 0);
```

<img width="692" alt="Screenshot 2024-07-26 at 1 22 17 PM" src="https://github.com/user-attachments/assets/9ea82c5e-28b0-4de6-805d-9c76051e82a6">
<br>

** o. Compare two strings and print the value ‘yes’ if they are equal, else print ‘no’. ** <br>

``` mySQL
   SELECT STRCMP('Girish', 'girish') As 'cmp_Value';
```

<img width="414" alt="Screenshot 2024-07-26 at 1 23 59 PM" src="https://github.com/user-attachments/assets/bd0dbb3b-303f-462f-8a21-f7954a4e2b50">
<br>

** p. Simulate the “IF... ELSE” construct in MySQL for a mark and grade setup. ** <br>

``` mySQL
   SELECT IF(500>100, "YES", "NO");
```

<img width="289" alt="Screenshot 2024-07-26 at 1 25 18 PM" src="https://github.com/user-attachments/assets/267b3cae-0090-4e61-961d-13fe4ab945ec">
<br>

** q. Use IFNULL to check whether a mathematical expression gives a NULL value or not. ** <br>

``` mySQL
   SELECT isnull(null);
```

<img width="207" alt="Screenshot 2024-07-26 at 1 26 32 PM" src="https://github.com/user-attachments/assets/d2f4371d-2407-49f5-a3f0-99a573e827ac">
<br>
















