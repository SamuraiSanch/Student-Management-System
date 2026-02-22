#include "StudentSystem.h"
#include <iostream>

void StudentSystem::addStudent(Student& student) {
    student.id = m_id;
    m_students[m_id] = student;
    ++m_id;
}
void StudentSystem::showAllStudents() {
        auto it = m_students.begin();
        while (it != m_students.end()) {
            std::cout << "ID: " << it->first << " contains student " << it->second << '\n';
            ++it;
        }
}
void StudentSystem::removeStudent(const int id) {
    m_students.erase(id);
}
Student* StudentSystem::getStudent(const int id) {
    auto it = m_students.find(id);
    if (it != m_students.end()) {
        return &(it->second);
    }
    else
        throw std::runtime_error("Student not found");

}
Student* StudentSystem::getStudent(const std::string& name) {
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (it->second.name == name)
            return &(it->second);
        ++it;
    }
    throw std::runtime_error("Student not found");
}
void StudentSystem::showStudentsByFaculty(const std::string& faculty) {
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (it->second.faculty == faculty)
            std::cout << it->second;
        ++it;
    }
}