#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H
#include "Student.h"
#include <set>

class StudentSystem {
private:
    int m_id = 1;
    std::map<int, Student> m_students;           // ID -> Student
    std::set<std::string> m_allSubjects;         // Всі предмети
    std::map<std::string, int> m_facultyCount;   // Факультет -> кількість

public:
    void addStudent(Student& student);
    void showAllStudents();
    void removeStudent(const int id);
    Student* getStudent(const int id);
    Student* getStudent(const std::string& name);
    void showStudentsByFaculty(const std::string& faculty);

    void addGrade(const int id, const std::string& subject, const int grade);
    void addGrade(const std::string& name, const std::string& subject, const int grade);
    void showGrades(const int id);
    void showGrades(const std::string& name);
    double calculateAverage(const int id);
    double calculateAverage(const std::string& name);
    std::vector<Student> getTopStudents(const int n);
};

#endif