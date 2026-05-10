#include "ExchangeStudent.h"

ExchangeStudent::ExchangeStudent(string nid, string nname, string nemail, float ngpa) : Student(nid, nname, nemail, ngpa)
{
}

void ExchangeStudent::calculateGPA()
{
}

void ExchangeStudent::viewTranscript() const
{
}

void ExchangeStudent::displayProfile() const
{
    cout << "ID: " << id << "; Name: " << name << "; Type: Exchange (Pass/Fail)" << endl;
}