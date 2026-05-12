#include "ScholarshipStudent.h"
#include <iostream>
ScholarshipStudent::ScholarshipStudent(string id, string n, string e, float g) : Student(id, n, e, g) {}
void ScholarshipStudent::calculateGPA()
{
    if (gpa < 3.0)
        status = "Probation";
}
void ScholarshipStudent::viewTranscript() const
{
    cout << "Scholarship Transcript - ID: " << ID << " Status: " << status << endl;
}