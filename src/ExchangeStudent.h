#ifndef EXCHANGESTUDENT_H
#define EXCHANGESTUDENT_H

#include "Student.h"

using namespace std;

class ExchangeStudent : public Student
{
public:
    ExchangeStudent(string nid = " ", string nname = " ", string nemail = " ", float ngpa = 0.0);
    void calculateGPA() override;
    void viewTranscript() const override;
    void displayProfile() const override;
};

#endif