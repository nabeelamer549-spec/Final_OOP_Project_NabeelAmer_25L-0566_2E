#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "AcademicEntity.h"

using namespace std;

class Student : public AcademicEntity
{
protected:
    string id;
    string name;
    string email;
    float gpa;
    string status;

public:
    Student(string nid = " ", string nname = " ", string nemail = " ", float ngpa = 0.0);
    virtual void calculateGPA() = 0;
    virtual void viewTranscript() const = 0;
    virtual void displayProfile() const = 0;
    virtual ~Student();
};

#endif