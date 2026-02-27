# 🎓 Student Management System

A console-based student management system built with C++ and STL containers for efficient data handling and academic record keeping.

![Demo](screenshots/demo.png)

## 📋 Description

This program simulates a university student management system with comprehensive CRUD operations, grade tracking, and statistical analysis. It demonstrates practical usage of C++ STL containers and algorithms.

## 🎯 Features

### Student Management
- ✅ Add new students with personal information
- ✅ Remove students by ID
- ✅ Search students by ID or name
- ✅ Display all students
- ✅ Filter students by faculty

### Grade Management
- ✅ Add grades for specific subjects
- ✅ View all grades for a student
- ✅ Calculate average grade across all subjects
- ✅ Support for multiple subjects per student

### Statistics & Analytics
- ✅ **Top 5 Students** — ranked by average grade
- ✅ **Faculty Statistics** — student count per faculty
- ✅ **Popular Subjects** — most studied subjects
- ✅ **Excellent Students** — students with average ≥ 90

### Data Persistence
- ✅ Save all data to CSV file
- ✅ Load data from CSV file
- ✅ Automatic data validation

## 🛠️ Technologies

- **C++11** (STL containers, algorithms, lambda functions)
- **Data Structures:**
  - `std::map<int, Student>` — fast student lookup by ID
  - `std::map<string, vector<int>>` — grades organized by subject
  - `std::vector` — dynamic arrays for collections
  - `std::pair` — for ranked data (ID + grade)
- **Algorithms:**
  - `std::sort` with custom comparators
  - `std::accumulate` for grade calculations
  - `std::find_if` for conditional search
- **File I/O:** CSV format for data persistence

## 🚀 How to Run

### Compilation (Visual Studio):
1. Open the project in Visual Studio
2. Press `F5` (Run)

### Compilation (GCC/Clang):
```bash
g++ -std=c++11 main.cpp Menu.cpp StudentSystem.cpp -o student_system
./student_system
```

### Compilation (CMake):
```bash
mkdir build && cd build
cmake ..
make
./student_system
```

## 📸 Demonstration

### Program
![Program](screenshots/demo.gif)

## 📂 Project Structure
```
student-management-system/
├── main.cpp              # Entry point
├── Student.h             # Student structure with operator overloads
├── StudentSystem.h       # Core system interface
├── StudentSystem.cpp     # Implementation of all features
├── Menu.h                # Menu interface
├── Menu.cpp              # Interactive console menu
├── README.md             # This file
├── Students.txt          # Sample data file (generated)
└── screenshots/
    ├── demo.png
    ├── menu.png
    └── statistics.png
```

## 💾 Data Format

The system uses CSV format for data storage:
```csv
# Students
1,John Smith,20,Computer Science
2,Alice Brown,19,Physics

# Grades
1,Math,85,90,95
1,Programming,92,88
2,Math,92,88,90
```

## 🎓 What I Learned

### STL Containers & Data Structures:
- Working with `std::map` for associative arrays
- Nested containers (`map<string, vector<int>>`)
- Efficient data lookup and manipulation
- Iterator patterns and best practices

### Algorithms & Functional Programming:
- Custom sorting with lambda comparators
- Aggregate operations with `std::accumulate`
- Conditional filtering and searching
- Function overloading for flexible interfaces

### Software Design:
- Separation of concerns (Menu, System, Data)
- Exception handling for error management
- File I/O with proper error checking
- CRUD operations implementation

### Real-World Skills:
- Menu-driven application architecture
- Data persistence and validation
- User input handling and validation
- Statistical calculations and ranking

## 📋 Example Usage
```
=== STUDENT MANAGEMENT SYSTEM ===

1. Add Student
Enter choice: 1

--- Add Student ---
Name: John Smith
Age: 20
Faculty: Computer Science

--- Add Grade ---
Student ID: 1
Subject: Math
Grade: 92

--- Calculate Average ---
Student ID: 1
Average grade: 92.00

--- Top 5 Students ---
1. Student [1] have grade: 95.5
2. Student [3] have grade: 92.3
...
```

## 🔧 Future Improvements

- [ ] Export statistics to JSON/XML
- [ ] GUI version using Qt or ImGui
- [ ] Unit tests with Google Test
- [ ] Database integration (SQLite)
- [ ] Multi-user support with authentication
- [ ] Grade history and trends
- [ ] Attendance tracking

## 📝 License

MIT License — free to use and modify.

## 👤 Author

**Oleksandr Kopii**  
GitHub: [@SamuraiSanch](https://github.com/SamuraiSanch)  

---

⭐ If you found this project helpful, please give it a star!
```
