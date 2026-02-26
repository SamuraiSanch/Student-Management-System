#include "Menu.h"

bool Menu::getMenu() {
    bool finish = false;
    do {
        int8_t choice;
        do {
            std::cout << "\n=== STUDENT MANAGEMENT SYSTEM ===\n\n"
                << "1. Add Student\n2. Remove Student\n3. Find Student\n4. Show All Students\n5. Add Grade\n6. Show Student Grades\n"
                << "7. Calculate Average Grade\n8. Top 5 Students\n9. Faculty Statistics\n10. Save to File\n11. Load from File\n0. Exit\n" << std::endl;
            std::cin >> choice;
        } while (choice < 0 && choice > 11);
        switch (choice) {
        case 0: std::cout << "\n--- Exit ---\n"; finish = true; break;
        case 1: { std::cout << "\n--- Add Student ---\n"; Student newStudent; std::cin >> newStudent; m_studsystem.addStudent(newStudent); break; }
        case 2: { std::cout << "\n--- Remove Student ---\n"; std::cout << "Enter id to remove: "; int16_t id; std::cin >> id; m_studsystem.removeStudent(id); break; }
        case 3: std::cout << "\n--- Find Student ---\n"; break;
        case 4: std::cout << "\n--- Show All Students ---\n"; break;
        case 5: std::cout << "\n--- Add Grade ---\n"; break;
        case 6: std::cout << "\n--- Show Student Grades ---\n"; break;
        case 7: std::cout << "\n--- Calculate Average Grade ---\n"; break;
        case 8: std::cout << "\n--- Top 5 Students ---\n"; break;
        case 9: std::cout << "\n--- Faculty Statistics ---\n"; break;
        case 10: std::cout << "\n--- Save to File ---\n"; break;
        case 11: std::cout << "\n--- Load from File ---\n"; break;
        default: std::cout << "\n--- Wrong choice. Please, try again. ---\n"; break;
        }
    } while (!finish);
    std::cout << "\nThank you for using our Student Management System <3.\n";
}