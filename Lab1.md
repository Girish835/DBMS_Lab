**a. Write an SQL Query to find the year from date.**

```mySQL
SELECT YEAR(CURRDATE()) as year;
```

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
