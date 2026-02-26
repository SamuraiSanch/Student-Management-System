#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ostream>
#include <istream>
struct Student {
    int id;
    std::string name;
    int age;
    std::string faculty;

    // Предмети та оцінки: "Math" -> [85, 90, 92]
    std::map<std::string, std::vector<int>> grades;
};
inline std::istream& operator>> (std::istream& in, Student& s) {
    std::cout << "Name: ";
    std::getline(in, s.name);
    std::cout << "Age: ";
    in >> s.age;
    std::cout << "Faculty: ";
    std::getline(in, s.faculty);
    return in;
}
inline std::ostream& operator<< (std::ostream& out, const Student& s) {
    out << '[' << s.id << "] " << s.name << '(' << s.age << "y) is studying on faculty: " << s.faculty;
    return out;
}

#endif