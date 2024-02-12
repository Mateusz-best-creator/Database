#include "../include/student.h"
#include <iostream>

Student::Student(std::string name, std::string surname, std::string street, int id, std::string pesel, Gender gender)
    : name(name), surname(surname), street(street), id(id), pesel(pesel), gender(gender) {}

Student::~Student() {}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "ID: " << student.id << "\n";
    os << "Student fullname: " << student.name << " " << student.surname << "\n";
    os << "Street: " << student.street << "\n";
    os << "Pesel: " << student.pesel << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Student& student)
{
    std::cout << "Enter ID: ";
    is >> student.id;
    std::cout << "Enter name: ";
    is >> student.name;
    std::cout << "Enter surname: ";
    is >> student.surname;
    std::cout << "Enter street: ";
    is >> student.street;
    std::cout << "Enter pesel: ";
    is >> student.pesel;
    return is;
}