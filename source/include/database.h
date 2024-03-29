#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <vector>
#include <climits>
#include "student.h"

/**
 * @brief Maximum value for index.
 * 
 * This constant defines the maximum value for the index used in the Database class.
 */
const int MAX_INDEX = INT_MAX;

/**
 * @brief Database class for managing student records.
 * 
 * This class provides functionality for managing a database of student records.
 * You can add students, display all students, search students by different properties,
 * sort and remove them.
 */
class Database
{
private:
    std::vector<Student> students;

public:
    Database();
    ~Database();

    bool add(const Student& student);
    void display() const;
    bool search_by_surname(const std::string& surname) const;
    bool search_by_pesel(const std::string& pesel) const;
    void sort_by_pesel();
    void sort_people_by_surname();
    bool remove_by_index(int);

    std::vector<Student>& get_students() { return students; }
};

#endif