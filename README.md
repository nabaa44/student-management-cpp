# Student Management System
A C++ console application for managing student records.

## Features
- Add Student
- Display All Students
- Search Student by ID
- Search Student by Name
- Sort Students by Grade
- Letter Grade System (A, B, C, D, F)

## How to Compile & Run
```
g++ main.cpp -o student_system
./student_system
```

## Sample Output
```
How many students? 3

1.Add  2.Display  3.Search by ID  4.Search by Name  5.Sort by Grade  0.Exit

Choice: 1
Enter ID: 101
Enter Name: Ali Hassan
Enter Grade: 88
Student added! (1/3)

Choice: 5
Sorted! Displaying from highest to lowest:
ID: 101  Name: Ali Hassan  Grade: 88 (B)
```

## Concepts Used
- struct
- Arrays
- Functions
- Control flow (if, for, switch)

## File Structure
```
student_management/
├── main.cpp
└── README.md
```
