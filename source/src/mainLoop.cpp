#include "../include/database.h"
#include "../include/student.h"
#include "../include/mainLoop.h"
#include <iostream>

void display_options()
{
    std::cout << "Choose one of the following options:\n";
    std::cout << "1) Add person\t 2) Display all records\t 3) Search for person by surname" << std::endl;
    std::cout << "4) Search for person by PESEL\t 6) Sort people by PESEL\t 7) Sort people by surname" << std::endl;
    std::cout << "8) Remove someone by index\t 9) Display options\t Other) Quit the database" << std::endl;
}

void MainLoop::Run()
{
    Database database;
    display_options();
    int option;
    Student temp;
    
    std::cout << "\nYour choose: ";
    while (std::cin >> option && option >= 1 && option <= 8)
    {
        switch(option)
        {
        case 1:
            std::cin >> temp;
            database.add(temp);
            break;
        case 2:
            database.display();
            break;
        default:
            return;
        }
        std::cout << "\nYour choose: ";
    } 
}