#include "ExchangeStudent.h"
#include <iostream>
ExchangeStudent::ExchangeStudent(string id, string n, string e, float g) : Student(id, n, e, g) {}
void ExchangeStudent::calculateGPA()
{
    status = (gpa >= 2.0) ? "Pass" : "Fail";
}
void ExchangeStudent::viewTranscript() const
{
    cout << "Exchange Transcript - ID: " << ID << " Status: " << status << endl;
}