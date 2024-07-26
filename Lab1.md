**a. Write an SQL Query to find the year from date.**

```mySQL
SELECT YEAR(CURDATE()) as year;
```
<img width="306" alt="Screenshot 2024-07-26 at 12 31 31 PM" src="https://github.com/user-attachments/assets/d1ee182a-124e-47d9-b88a-e16043e10b92">


**b. Check whether date passed to Query is the date of a given format or no**

```mySQL
SELECT str_to_date('2024-07-18','%y-%m-%d') as valid_date;
```

**c. Find the size of the SCHEMA/USER.**

```mySQL
  SELECT
   SUM(ROUND(((DATA_LENGTH + INDEX_LENGTH) / 1024 / 1024), 2)) AS "SIZE IN MB"
   FROM INFORMATION_SCHEMA.TABLES
   WHERE TABLE_SCHEMA = "SCHEMA-NAME";
```
