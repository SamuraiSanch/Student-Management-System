#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <map>
#include <vector>
#include <ostream>

struct Student {
    int id;
    std::string name;
    int age;
    std::string faculty;

    // Предмети та оцінки: "Math" -> [85, 90, 92]
    std::map<std::string, std::vector<int>> grades;
};

std::ostream& operator<< (std::ostream& out, const Student& s) {
    out << '[' << s.id << "] " << s.name << '(' << s.age << "y) is studying on faculty: " << s.faculty;
    return out;
}

#endif