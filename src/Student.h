#ifndef STUDENT_H
#define STUDENT_H
#include "AcademicEntity.h"

class Student : public AcademicEntity
{
protected:
    float gpa;
    string status;

public:
    Student(string id = " ", string n = " ", string e = " ", float g = 0.0);
    virtual void calculateGPA() = 0;
    virtual void viewTranscript() const = 0;
    void displayProfile() const override;
};
#endif