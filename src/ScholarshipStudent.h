#ifndef SCHOLARSHIPSTUDENT_H
#define SCHOLARSHIPSTUDENT_H
#include "Student.h"

class ScholarshipStudent : public Student
{
public:
    ScholarshipStudent(string id = " ", string n = " ", string e = " ", float g = 0.0);
    void calculateGPA() override;
    void viewTranscript() const override;
};
#endif