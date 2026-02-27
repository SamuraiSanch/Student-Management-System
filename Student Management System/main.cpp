#include <iostream>
#include "Menu.h"
int main()
{
    StudentSystem studentSystem;
    Menu menu(studentSystem);
    try {
        menu.getMenu();
    }
    catch (std::runtime_error e) {
        std::cerr << e.what();
    }
}

