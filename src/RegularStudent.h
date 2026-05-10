#ifndef REGULARSTUDENT_H
#define REGULARSTUDENT_H

#include "Student.h"

using namespace std;

class RegularStudent : public Student
{
public:
    RegularStudent(string nid = " ", string nname = " ", string nemail = " ", float ngpa = 0.0);
    void calculateGPA() override;
    void viewTranscript() const override;
    void displayProfile() const override;
};

#endif