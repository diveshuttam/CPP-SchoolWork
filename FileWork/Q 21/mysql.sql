DROP DATABASE Filework;
CREATE DATABASE Filework;
USE Filework;
CREATE TABLE Employee
(
Eno      integer   NOT NULL  PRIMARY KEY,
Fname    char(20)  NOT NULL,
Lname    char(20)  NOT NULL,
Design   char(20),
CHECK    (Design IN ('mgr','smgr','clerk','supervisor') ),
Deptno   integer   NOT NULL,
Sal      integer,
CHECK    (Sal BETWEEN 5000 and 25000),
Gender   char(2)   NOT NULL,
CHECK    (Gender IN ('M','F') ),
Dob      DATE,
Doj      DATE,
CHECK    (Doj > Dob)
);
CREATE TABLE Dept
(
Dno      integer   NOT NULL  PRIMARY KEY,
Dname    char(20)  NOT NULL  UNIQUE,
Loc      char(20)  NOT NULL
);
CREATE TABLE Sal
(
Grade    integer   NOT NULL  PRIMARY KEY,
CHECK    (Grade BETWEEN 1 and 5),
Up_limit integer   NOT NULL,
CHECK    (Up_limit BETWEEN 5000 and 25000),
Lo_limit integer   NOT NULL,
CHECK    (Lo_limit BETWEEN 5000 and 25000)
);

INSERT INTO Employee VALUES(1000,'Abhishek','Garg','Clerk',2000,5500,'M',
"12-12-1985","10-11-2005");
INSERT INTO Employee VALUES(1000,'Abhishek','Garg','Clerk',2000,5500,'M',
"1985-12-12","2005-11-10");
INSERT INTO Employee VALUES(1001,'Prachi','Goyel','Clerk',2000,5200,'F',
"1986-11-10","2008-10-05");
INSERT INTO Employee VALUES(1003,'Simran','Dua','Clerk',2000,5300,'F',
"1983-05-07","2007-07-10");
INSERT INTO Employee VALUES(1004,'Risika','Pal','Mgr',2000,21000,'F',
"1980-01-14","2001-01-13");
INSERT INTO Employee VALUES(1005,'Mohit','Batra','Smgr',2000,25000,'M',
"1947-08-15","1975-05-11");
INSERT INTO Dept Values(2000,'Sales',NULL);
INSERT INTO Dept Values(2000,'Sales','Delhi');
INSERT INTO Employee VALUES(1006,'Sonal','Gupta','Superviser',2000,25000,
'F',"1949-12-03","1975-09-13");