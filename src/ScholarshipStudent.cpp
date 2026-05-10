#include "ScholarshipStudent.h"

ScholarshipStudent::ScholarshipStudent(string nid, string nname, string nemail, float ngpa) : Student(nid, nname, nemail, ngpa)
{
}

void ScholarshipStudent::calculateGPA()
{
    if (gpa < 3.0)
    {
        status = "Probation";
    }
}

void ScholarshipStudent::viewTranscript() const
{
}

void ScholarshipStudent::displayProfile() const
{
    cout << "ID: " << id << "; Name: " << name << "; GPA: " << gpa << "; Status: " << status << endl;
}