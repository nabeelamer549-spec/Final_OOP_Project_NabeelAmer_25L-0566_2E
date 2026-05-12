#include "Teacher.h"
#include <iostream>

Teacher::Teacher(string id, string n, string e, string *c, int s)
    : AcademicEntity(id, n, e, "Teachers.txt"), DatabaseManager()
{
    size = s;
    avgFeedback = 0.0;
    if (s > 0 && c != nullptr)
    {
        courses = new string[size];
        for (int i = 0; i < size; i++)
            courses[i] = c[i];
    }
    else
    {
        courses = nullptr;
    }
}

void Teacher::displayProfile() const
{
    cout << "ID: " << ID << " | Name: " << name << " | Email: " << email << endl;
}

void Teacher::feedback()
{
    cout << "Feedback System Active for " << name << endl;
}

Teacher::~Teacher()
{
    if (courses != nullptr)
        delete[] courses;
}