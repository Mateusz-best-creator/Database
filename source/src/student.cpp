#include "../include/student.h"

Student::Student(std::string name, std::string surname, std::string street, int id, std::string pesel, Gender gender)
    : name(name), surname(surname), street(street), id(id), pesel(pesel), gender(gender) {}

Student::~Student() {}