#include "RegularStudent.h"
#include <iostream>

RegularStudent::RegularStudent(string id, string n, string e, float g) : Student(id, n, e, g) {}

void RegularStudent::calculateGPA()
{
    if (courseCount == 0)
    {
        gpa = 0.0;
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
}

void RegularStudent::viewTranscript() const
{
    cout << "\n=== Regular Student Transcript ===" << endl;
    cout << "ID: " << ID << " | Name: " << name << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Courses:" << endl;
    for (int i = 0; i < courseCount; i++)
    {
        cout << "  " << courseIDs[i] << ": " << courseGrades[i] << "%" << endl;
    }
}