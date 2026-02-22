#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H
#include "Student.h"
#include <set>

class StudentSystem {
private:
    std::map<int, Student> m_students;           // ID -> Student
    std::set<std::string> m_allSubjects;         // Всі предмети
    std::map<std::string, int> m_facultyCount;   // Факультет -> кількість

public:
    void addStudent();
    void showAllStudents();
};

#endif