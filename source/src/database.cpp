#include "../include/database.h"
#include <iostream>
#include <algorithm>

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
    std::cout << "Students Database:\n\n";
    if (students.size() == 0)
    {
        std::cout << "Database is empty" << std::endl;
        return;
    }
    for (const auto& student : students)
    {
        std::cout << student;
        std::cout << "\n===================\n";
    }
}

bool Database::search_by_surname(const std::string& surname) const
{
    for (const auto& student : students)
    {
        if (student.get_surname() == surname)
        {
            std::cout << "Student found, data:\n";
            std::cout << student;
            return true;
        }
    }
    std::cout << "Student with this surname: " << surname << " not found in our database\n";
    return false;
}

bool Database::search_by_pesel(const std::string& pesel) const
{
    for (const auto& student : students)
    {
        if (student.get_pesel() == pesel)
        {
            std::cout << "Student found, data:\n";
            std::cout << student;
            return true;
        }
    }
    std::cout << "Student with this pesel: " << pesel << " not found in our database\n";
    return false;
}

// Sort students based on their PESEL numbers
void Database::sort_by_pesel()
{
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return std::stoi(a.get_pesel()) < std::stoi(b.get_pesel());
    });
}

// Sort students based on their surnames
void Database::sort_people_by_surname()
{
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.get_surname() < b.get_surname();
    });
}

bool Database::remove_by_index(int index_to_remove)
{
    if (index_to_remove > MAX_INDEX)
    {
        std::cout << "Index bigger than MAX_INDEX" << std::endl;
        return false;
    }
    auto it = std::find_if(students.begin(), students.end(), [index_to_remove](const Student& s)
    {
        return s.get_id() == index_to_remove;
    });

    if (it == students.end())
    {
        std::cout << "Students with ID = " << index_to_remove << " does not exist in our database" << std::endl;
        return false;
    }
    std::cout << "Removing student with ID = " << index_to_remove << std::endl;
    students.erase(it);
    return true;
}


