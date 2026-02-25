#include "StudentSystem.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
void StudentSystem::addStudent(Student& student) {
    student.id = m_id;
    m_students[m_id] = student;
    ++m_id;
}
void StudentSystem::showAllStudents() {
        auto it = m_students.begin();
        if (it == m_students.end())
            throw std::runtime_error("ShowAllStudents can't find students.");
        while (it != m_students.end()) {
            std::cout << "ID: " << it->first << " contains student " << it->second << '\n';
            ++it;
        }
}
void StudentSystem::removeStudent(const int id) {
    if (m_students.erase(id) == 0)
        throw std::runtime_error("RemoveStudent can't find student.");
}
Student* StudentSystem::getStudent(const int id) {
    auto it = m_students.find(id);
    if (it != m_students.end()) {
        return &(it->second);
    }
    else
        throw std::runtime_error("GetStudent (int) can't find student.");

}
Student* StudentSystem::getStudent(const std::string& name) {
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (it->second.name == name)
            return &(it->second);
        ++it;
    }
    throw std::runtime_error("GetStudent (string) can't find student.");
}
void StudentSystem::showStudentsByFaculty(const std::string& faculty) {
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (it->second.faculty == faculty)
            std::cout << it->second;
        ++it;
    }
}
void StudentSystem::addGrade(const int id, const std::string& subject, const int grade) {
    try {
        m_students.at(id).grades[subject].push_back(grade);
    }
    catch (const std::out_of_range) {
        throw std::runtime_error("AddGrade (int) can't find student.");
    }
}
void StudentSystem::addGrade(const std::string& name, const std::string& subject, const int grade) {
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (it->second.name == name)
            it->second.grades[subject].push_back(grade);
        ++it;
    }
}
void StudentSystem::showGrades(const int id) {
    auto it = m_students.find(id);
    if (it == m_students.end()) {
        throw std::runtime_error("ShowGrades (int) can't find student.");
    }

    std::cout << "Grades of [" << id << "] " << it->second.name << ":\n";
    for (auto const& grades : it->second.grades) {
        std::cout << "Subject: " << grades.first << " | Grades: ";
        for (int grade : grades.second) {
            std::cout << grade << ' ';
        }
        std::cout << "\n";
    }
}
void StudentSystem::showGrades(const std::string& name) {
    bool found = false;
    auto it = m_students.begin();
    while (it != m_students.end() && !found) {
        if (it->second.name == name) {
            found = true;
            std::cout << "Grades of [" << it->first << "] " << it->second.name << ":\n";
            for (auto const& grades : it->second.grades) {
                std::cout << "Subject: " << grades.first << " | Grades: ";
                for (const int grade : grades.second) {
                    std::cout << grade << ' ';
                }
                std::cout << "\n";
            }
        }
        ++it;
    }
    if (!found)
        throw std::runtime_error("ShowGrades (string) can't find student.");
}
double StudentSystem::calculateAverage(const int id) {
    auto it = m_students.find(id); // it->second - Student
    if (it == m_students.end()) {
        throw std::runtime_error("ShowGrades (int) can't find student.");
    }
    int sumOfGrades = 0;
    int countOfGrades = 0;
    for (auto const& grades : it->second.grades) {
        sumOfGrades += std::accumulate(grades.second.begin(), grades.second.end(), 0);
        countOfGrades += grades.second.size();
    }
    
    return countOfGrades > 0 ? static_cast<double>(sumOfGrades) / countOfGrades : 0.0;
}
double StudentSystem::calculateAverage(const std::string& name) {
    bool found = false;
    int sumOfGrades = 0;
    int countOfGrades = 0;
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (it->second.name == name) {
            found = true;
            for (auto const& grades : it->second.grades) {
                sumOfGrades += std::accumulate(grades.second.begin(), grades.second.end(), 0);
                countOfGrades += grades.second.size();
            }
            return countOfGrades > 0 ? static_cast<double>(sumOfGrades) / countOfGrades : 0.0;
        }
        ++it;
    }
    if (!found)
        throw std::runtime_error("CalculateAverage (string) can't find student.");
    
}
std::vector<std::pair<int, double>> StudentSystem::getTopStudents(const int n) {
    std::vector<std::pair<int, double>> topStudents;
    topStudents.reserve(m_students.size());
    auto it = m_students.begin();
    while (it != m_students.end()) {
        topStudents.push_back(std::make_pair(it->first, calculateAverage(it->first)));
        ++it;
    }
    std::sort(topStudents.begin(), topStudents.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
        return a.second > b.second;
        });
    topStudents.resize(n);
    return topStudents;

}
std::map<std::string, int> StudentSystem::getFacultyStatistics() {
    std::map<std::string, int> facultyStatistics;

    if (m_students.empty())
        throw std::runtime_error("GetFacultyStatistics: can't find any faculty.");
    for (auto it = m_students.begin(); it != m_students.end(); ++it) {
        facultyStatistics[it->second.faculty]++;
    }


    return facultyStatistics;

}
std::map<std::string, int> StudentSystem::getPopularSubjects() {
    std::map<std::string, int> popularSubjects;
    if (m_students.empty())
        throw std::runtime_error("GetPopularSubjects: can't find any student.");
    for (auto it = m_students.begin(); it != m_students.end(); ++it) {
        for (auto itsubj = it->second.grades.begin(); itsubj != it->second.grades.end(); ++itsubj)
        popularSubjects[itsubj->first]++;
    }
    return popularSubjects;
}
std::vector<Student> StudentSystem::getExcellentStudents() {
    std::vector<Student> excellentStudents;
    auto it = m_students.begin();
    while (it != m_students.end()) {
        if (calculateAverage(it->second.id) >= 90) {
            excellentStudents.push_back(it->second);
        }
        ++it;
    }
    return excellentStudents;
}
void StudentSystem::saveToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) 
        throw std::runtime_error("Cannot open file for writing");

    if (m_students.empty())
        throw std::runtime_error("Students empty for writing");
    file << "# Students\n";
    for (auto it = m_students.begin(); it != m_students.end(); ++it) {
        file << it->second.id << "," << it->second.name << "," << it->second.age << "," << it->second.faculty << "\n";
    }

    file << "\n# Grades\n";
    for (auto it = m_students.begin(); it != m_students.end(); ++it) {
        for (auto itgrade = it->second.grades.begin(); itgrade != it->second.grades.end(); ++itgrade) {
            file << it->first << "," << itgrade->first;
            for (const auto& gradevec : itgrade->second) {
                file << "," << gradevec;
            }
            file << "\n";
        }
    }

    file.close();
    std::cout << "Data loaded to: " << filename << std::endl;
}
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
void StudentSystem::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    m_students.clear();

    std::string line;
    bool readingStudents = false;
    bool readingGrades = false;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line == "# Students") {
            readingStudents = true;
            readingGrades = false;
            continue;
        }
        else if (line == "# Grades") {
            readingStudents = false;
            readingGrades = true;
            continue;
        }

        if (readingStudents) {
            std::vector<std::string> parts = split(line, ',');

            Student s;
            s.id = std::stoi(parts[0]);
            s.name = parts[1];
            s.age = std::stoi(parts[2]);
            s.faculty = parts[3];

            m_students[s.id] = s;
        }
        else if (readingGrades) {
            std::vector<std::string> parts = split(line, ',');

            int studentId = std::stoi(parts[0]);
            std::string subject = parts[1];

            std::vector<int> grades;
            for (size_t i = 2; i < parts.size(); ++i) {
                grades.push_back(std::stoi(parts[i]));
            }

            m_students[studentId].grades[subject] = grades;
        }
    }

    file.close();
    std::cout << "Data loaded from: " << filename << std::endl;
}