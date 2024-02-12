#include "../include/database.h"
#include "../include/student.h"
#include "../include/mainLoop.h"
#include <iostream>

void display_options()
{
    std::cout << "Choose one of the following options:\n";
    std::cout << "1) Add person\t 2) Display all records\t 3) Search for person by surname" << std::endl;
    std::cout << "4) Search for person by PESEL\t 5) Sort people by PESEL\t 6) Sort people by surname" << std::endl;
    std::cout << "7) Remove someone by index\t 8) Display options\t Other) Quit the database" << std::endl;
}

void MainLoop::Run()
{
    Database database;
    display_options();
    int option, index;
    Student stu;
    std::string sur, pesel;
    
    std::cout << "\nYour choose: ";
    while (std::cin >> option && option >= 1 && option <= 8)
    {
        switch(option)
        {
        case 1:
            std::cin >> stu;
            database.add(stu);
            break;
        case 2:
            database.display();
            break;
        case 3:
            std::cout << "Give some surname: ";
            std::cin >> sur;
            database.search_by_surname(sur);
            break;
        case 4:
            std::cout << "Give some pesel: ";
            std::cin >> pesel;
            database.search_by_pesel(pesel);
            break;
        case 5:
            database.sort_by_pesel();
            break;
        case 6:
            database.sort_people_by_surname();
            break;
        case 7:
            std::cout << "Give index to remove: ";
            std::cin >> index;
            database.remove_by_index(index);
            break;
        case 8:
            display_options();
            break;
        default:
            return;
        }
        std::cout << "\nYour choose: ";
    } 
}