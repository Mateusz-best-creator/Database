#include "../include/student.h"
#include <iostream>
#include <vector>

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
    while (!student.validatePESEL(student.pesel))
    {
        std::cout << "Pesel is incorrect, please enter it again: ";
        is >> student.pesel;
        while (std::cin.get() != '\n')
            continue;
    }
    return is;
}

bool Student::validatePESEL(const std::string& pesel) const
{
    // Check if PESEL length is correct
    if (pesel.length() != 11)
        return false;

    // Convert PESEL digits to integers
    std::vector<int> digits;
    for (char c : pesel) 
    {
        if (!isdigit(c))
            return false; // Non-digit character in PESEL
        digits.push_back(c - '0');
    }

    // Calculate checksum
    int checksum = 1 * digits[0] +
                   3 * digits[1] +
                   7 * digits[2] +
                   9 * digits[3] +
                   1 * digits[4] +
                   3 * digits[5] +
                   7 * digits[6] +
                   9 * digits[7] +
                   1 * digits[8] +
                   3 * digits[9];

    // Check if checksum is valid
    int lastDigit = checksum % 10;
    if (lastDigit != 0) 
    {
        lastDigit = 10 - lastDigit;
    }
    return lastDigit == digits[10];
}

