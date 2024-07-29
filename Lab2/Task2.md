### a. Create the Student Schema

```sql

CREATE TABLE Student (
    Std_rollno INT PRIMARY KEY,
    Std_name VARCHAR(50),
    Dept VARCHAR(10),
    Course1 CHAR(10),
    Course2 CHAR(10),
    Course3 CHAR(10),
    Course4 CHAR(10),
    dob DATE NOT NULL,
    email VARCHAR(50) CHECK (email LIKE '%@nitt.edu')
);
```
### b. Insert at least 5 student records into the Student table

```sql

INSERT INTO Student (Std_rollno, Std_name, Dept, Course1, Course2, Course3, Course4, dob, email)
VALUES 
(1, 'Rahul', 'CSE', 'DBMS', 'OS', 'DS', 'CN', '1998-11-25', 'rahul@nitt.edu'),
(2, 'Sanya', 'EEE', 'DBMS', 'Circuit Theory', 'Signals', 'Control Systems', '1999-03-15', 'sanya@nitt.edu'),
(3, 'Amit', 'MME', 'Thermodynamics', 'Fluid Mechanics', 'Strength of Materials', 'Machine Design', '2000-05-10', 'amit@nitt.edu'),
(4, 'Deepak', 'CSE', 'DBMS', 'Programming', 'Data Structures', 'Algorithms', '2001-07-12', 'deepak@nitt.edu'),
(5, 'Priya', 'CE', 'Structural Analysis', 'Soil Mechanics', 'Concrete Technology', 'Surveying', '2002-09-18', 'priya@nitt.edu');
```

### c. Delete Course2 and Course3 attributes from the Student table

```sql

ALTER TABLE Student DROP COLUMN Course2;
ALTER TABLE Student DROP COLUMN Course3;
Step 4: Insert two new columns dob and email into the Student table
The columns dob and email are already added in the initial schema creation.
```
### d. Change Course1 datatype to VARCHAR(2)

```sql

ALTER TABLE Student MODIFY COLUMN Course1 VARCHAR(2);
```

### e. Update the column name Std_rollno to Std_rno
```sql

ALTER TABLE Student CHANGE Std_rollno Std_rno INT;
```

### f. Update all student records who pursue a course named "DBMS" to "OS"
```sql

UPDATE Student SET Course1 = 'OS' WHERE Course1 = 'DBMS';
```

### g. Delete a student record with a student name starting with the letter 'S'

```sql

DELETE FROM Student WHERE Std_name LIKE 'S%';
```

### h. Display all records in which a student has born after the year 2005

```sql

SELECT * FROM Student WHERE YEAR(dob) > 2005;
```

### i. Simulate DROP and TRUNCATE commands with the database you create 

```sql

DROP TABLE Student;
TRUNCATE TABLE Student;
```
