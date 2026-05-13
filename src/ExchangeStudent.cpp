#include "ExchangeStudent.h"
#include <iostream>

ExchangeStudent::ExchangeStudent(string id, string n, string e, float g) : Student(id, n, e, g) {}

void ExchangeStudent::calculateGPA()
{
    bool passed = true;
    for (int i = 0; i < courseCount; i++)
    {
        if (courseGrades[i] < 50)
        {
            passed = false;
            break;
        }
    }

    if (passed)
    {
        status = "Pass";
        gpa = 3.0;
    }
    else
    {
        status = "Fail";
        gpa = 0.0;
    }
}

void ExchangeStudent::viewTranscript() const
{
    cout << "\n=== Exchange Student Transcript ===" << endl;
    cout << "ID: " << ID << " | Name: " << name << endl;
    cout << "Status: " << status << " (Pass/Fail)" << endl;
}