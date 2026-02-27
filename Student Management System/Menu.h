#ifndef MENU_H
#define MENU_H
#include "StudentSystem.h"

class Menu {
private:
    StudentSystem &m_studsystem;
public:
    Menu(StudentSystem& studsystem) : m_studsystem(studsystem) {
    }
    void getMenu();
};

#endif