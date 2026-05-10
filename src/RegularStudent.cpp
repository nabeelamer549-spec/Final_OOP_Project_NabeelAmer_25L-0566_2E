#include "RegularStudent.h"

RegularStudent::RegularStudent(string nid, string nname, string nemail, float ngpa) : Student(nid, nname, nemail, ngpa)
{
}

void RegularStudent::calculateGPA()
{
}

void RegularStudent::viewTranscript() const
{
}

void RegularStudent::displayProfile() const
{
    cout << "ID: " << id << "; Name: " << name << "; GPA: " << gpa << endl;
}