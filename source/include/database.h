#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <vector>
#include "student.h"

class Database
{
private:
    std::vector<Student> students;

public:
    Database();
    ~Database();

    bool add(const Student& student);
    void display();
    bool search_by_surname();
    bool search_by_pesel();
};

#endif