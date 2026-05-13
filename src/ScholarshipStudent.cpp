#include "ScholarshipStudent.h"
#include <iostream>

ScholarshipStudent::ScholarshipStudent(string id, string n, string e, float g)
    : Student(id, n, e, g) {}

void ScholarshipStudent::calculateGPA()
{
    if (courseCount == 0)
    {
        gpa = 0.0;
        status = "Probation";
        return;
    }

    float total = 0;
    for (int i = 0; i < courseCount; i++)
    {
        if (courseGrades[i] >= 85)
            total += 4.0;
        else if (courseGrades[i] >= 75)
            total += 3.0;
        else if (courseGrades[i] >= 65)
            total += 2.0;
        else if (courseGrades[i] >= 50)
            total += 1.0;
        else
            total += 0.0;
    }
    gpa = total / courseCount;

    if (gpa < 2.5)
    {
        status = "Probation";
    }
    else
    {
        status = "Active";
    }
}

void ScholarshipStudent::viewTranscript() const
{
    cout << "\n=== Scholarship Student Transcript ===" << endl;
    cout << "ID: " << ID << " | Name: " << name << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Status: " << status << endl;
    if (status == "Probation")
    {
        cout << "WARNING: Scholarship at risk!" << endl;
    }
}