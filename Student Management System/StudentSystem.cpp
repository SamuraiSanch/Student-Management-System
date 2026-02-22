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
void StudentSystem::removeStudent(const Student& student) {
    m_students.erase(student.id);
}