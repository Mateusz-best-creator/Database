#include "../include/database.h"
#include <iostream>

Database::Database() {}

Database::~Database() {}

bool Database::add(const Student& student)
{
    for (const auto& stu : students)
    {
        if (stu.get_pesel() == student.get_pesel())
            return false;
    }
    students.push_back(student);
    return true;
}

void Database::display() const
{
    std::cout << "Students Database:\n";
    if (students.size() == 0)
    {
        std::cout << "Database is empty" << std::endl;
        return;
    }
    for (const auto& student : students)
    {
        std::cout << "ID: " << student.get_id() << std::endl;
        std::cout << "Student fullname: " << student.get_name() << " " << student.get_surname() << std::endl;
        std::cout << "Street: " << student.get_street() << std::endl;
        std::cout << "Pesel: " << student.get_pesel() << std::endl;
        std::cout << "\n===================\n";
    }
}

bool Database::search_by_surname() const
{
    return false;
}

bool Database::search_by_pesel() const
{
    return false;
}