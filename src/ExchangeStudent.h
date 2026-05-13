#ifndef EXCHANGESTUDENT_H
#define EXCHANGESTUDENT_H
#include "Student.h"

class ExchangeStudent : public Student
{
public:
    ExchangeStudent(string id = "", string n = "", string e = "", float g = 0.0);
    void calculateGPA() override;
    void viewTranscript() const override;
};
#endif