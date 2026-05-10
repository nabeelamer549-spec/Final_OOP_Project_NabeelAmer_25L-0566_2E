#ifndef SCHOLARSHIPSTUDENT_H
#define SCHOLARSHIPSTUDENT_H

#include "Student.h"

using namespace std;

class ScholarshipStudent : public Student
{
public:
    ScholarshipStudent(string nid = " ", string nname = " ", string nemail = " ", float ngpa = 0.0);
    void calculateGPA() override;
    void viewTranscript() const override;
    void displayProfile() const override;
};

#endif