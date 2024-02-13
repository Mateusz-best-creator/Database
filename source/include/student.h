#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>

/**
 * @brief Enumeration representing the gender of a student.
 */
enum class Gender { MALE = 0, FEMALE };

/**
 * @brief Class representing a student.
 * 
 * This class represents a student with attributes such as name, surname, street, PESEL, ID, and gender.
 */
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

    // Some getters
    std::string get_name() const { return name; }
    std::string get_surname() const { return surname; }
    std::string get_street() const { return street; }
    std::string get_pesel() const { return pesel; }
    int get_id() const { return id; }

    /**
     * @brief Validate the PESEL of the student.
     * 
     * @param pesel The PESEL to validate.
     * @return True if the PESEL is valid, false otherwise.
     */
    bool validatePESEL(const std::string& pesel) const;
    /**
     * @brief Overloaded insertion operator to output student information.
     * 
     * @param os The output stream.
     * @param student The student object.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    /**
     * @brief Overloaded extraction operator to input student information.
     * 
     * @param is The input stream.
     * @param student The student object.
     * @return Reference to the input stream.
     */
    friend std::istream& operator>>(std::istream& is, Student& student);
};

#endif