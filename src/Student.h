#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "AcademicEntity.h"
using namespace std;

class Student : public AcademicEntity
{
    string id;
    string name;
    string email;

public:
    Student(string nid, string nname, string nemail) : AcademicEntity(nid, nname, nemail)
    {
    }
    virtual void displayprofile() = 0;
    virtual void calculateGPA() = 0;
    virtual void viewtranscript() = 0;
};

#endif