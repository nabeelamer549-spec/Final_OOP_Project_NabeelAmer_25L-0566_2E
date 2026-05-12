#include "RegularStudent.h"
#include <iostream>

RegularStudent::RegularStudent(string id, string n, string e, float g) : Student(id, n, e, g) {}

void RegularStudent::calculateGPA()
{
}

void RegularStudent::viewTranscript() const
{
    cout << "Regular Transcript - ID: " << ID << " GPA: " << gpa << endl;
}