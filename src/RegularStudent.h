#ifndef REGULARSTUDENT_H
#define REGULARSTUDENT_H
#include "Student.h"

class RegularStudent : public Student
{
public:
    RegularStudent(string id = "", string n = "", string e = "", float g = 0.0);
    void calculateGPA() override;
    void viewTranscript() const override;
};
#endif