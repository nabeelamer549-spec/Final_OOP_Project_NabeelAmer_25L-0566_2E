#include "Student.h"
#include <iostream>

Student::Student(string id, string n, string e, float g) : AcademicEntity(id, n, e, "Students.txt")
{
    gpa = g;
    status = "Active";
}

void Student::displayProfile() const
{
    cout << "ID: " << ID << "; Name: " << name << "; GPA: " << gpa << "; Status: " << status << endl;
}