#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>

enum class Gender { MALE = 0, FEMALE };

class Student
{
private:
    std::string name, surname, street, pesel;
    int id;
    Gender gender;

public: 
    Student() = default;
    Student(std::string name, std::string surname, std::string street, int id, std::string pesel, Gender gender);
    ~Student();

    /*
    // We do not want to copy our student class
    Student(const Student& other) = delete;
    Student(const Student&& other) = delete;
    Student& operator=(const Student& other) = delete;
    */
    // Some getters
    std::string get_name() const { return name; }
    std::string get_surname() const { return surname; }
    std::string get_street() const { return street; }
    std::string get_pesel() const { return pesel; }
    int get_id() const { return id; }

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};

#endif