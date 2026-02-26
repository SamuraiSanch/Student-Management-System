#include "Menu.h"
#include <vector>
bool Menu::getMenu() {
    bool finish = false;
    do {
        int8_t choice;
        do {
            std::cout << "\n=== STUDENT MANAGEMENT SYSTEM ===\n\n"
                << "1. Add Student\n2. Remove Student\n3. Find Student\n4. Show All Students\n5. Add Grade\n6. Show Student Grades\n"
                << "7. Calculate Average Grade\n8. Top 5 Students\n9. Faculty Statistics\n10. Show Excellent Students\n11. Save to File\n12. Load from File\n0. Exit\n" << std::endl;
            std::cin >> choice;
        } while (choice < 0 && choice > 12);
        switch (choice) {
        case 0: std::cout << "\n--- Exit ---\n"; finish = true; break;
        case 1: { std::cout << "\n--- Add Student ---\n"; Student newStudent; std::cin >> newStudent; m_studsystem.addStudent(newStudent); break; }
        case 2: { std::cout << "\n--- Remove Student ---\n"; std::cout << "Enter id to remove: "; int16_t id; std::cin >> id; m_studsystem.removeStudent(id); break; }
        case 3: { std::cout << "\n--- Find Student ---\n"; std::cout << "Enter stident id to find: "; int16_t id; std::cin >> id; std::cout << "Main information about student: " << m_studsystem.getStudent(id); break; }
        case 4: { std::cout << "\n--- Show All Students ---\n"; m_studsystem.showAllStudents(); break; }
        case 5: { std::cout << "\n--- Add Grade ---\n"; std::cout << "Enter student id to add grade: "; int16_t id; std::cin >> id; std::cout << "Enter subject to add grade: "; std::string subject; std::getline(std::cin, subject); int16_t grade; do { std::cout << "Enter grade to add: "; std::cin >> grade; } while (grade < 0 && grade > 100); m_studsystem.addGrade(id, subject, grade); break; }
        case 6: { std::cout << "\n--- Show Student Grades ---\n"; std::cout << "Enter stident id to show grades: "; int16_t id; std::cin >> id; m_studsystem.showGrades(id); break; }
        case 7: { std::cout << "\n--- Calculate Average Grade ---\n"; std::cout << "Enter student id to calculate average grade: "; int16_t id; std::cin >> id; std::cout << "Average grade: " << m_studsystem.calculateAverage(id); break; }
        case 8: { std::cout << "\n--- Top 5 Students ---\n"; std::vector<std::pair<int, double>> topStudents = m_studsystem.getTopStudents(5); for (const auto& student : topStudents) { std::cout << "Student [" << student.first << "] have grade: " << student.second; } break; }
        case 9: { std::cout << "\n--- Faculty Statistics ---\n"; std::map<std::string, int> facultyStatistics; for (auto it = facultyStatistics.begin(); it != facultyStatistics.end(); ++it) { std::cout << it->first << '-' << it->second << '\n'; } break; }
        case 10: { std::cout << "\n--- Excellent Students ---\n"; std::vector<Student> excellentStudents = m_studsystem.getExcellentStudents(); for (const auto& student : excellentStudents) { std::cout << student << '\n'; }; break; }
        case 11: { std::cout << "\n--- Save to File ---\n"; m_studsystem.saveToFile("Students.txt"); break; }
        case 12: { std::cout << "\n--- Load from File ---\n"; m_studsystem.loadFromFile("Students.txt"); break; }
        default: std::cout << "\n--- Wrong choice. Please, try again. ---\n"; break;
        }
    } while (!finish);
    std::cout << "\nThank you for using our Student Management System <3.\n";
}