#include "Teacher.h"
#include <iostream>

Teacher::Teacher(string id, string n, string e, string *c, int s)
    : AcademicEntity(id, n, e, "Teachers.txt"), DatabaseManager()
{
    size = s;
    avgFeedback = 4.5;
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
    cout << "ID: " << ID << " | Name: " << name << " | Feedback: " << avgFeedback << endl;
}

void Teacher::addFeedback(int rating)
{
    if (rating >= 1 && rating <= 5)
    {
        avgFeedback = (avgFeedback + rating) / 2.0;
        cout << "Rating saved. Updated average for " << name << ": " << avgFeedback << endl;
    }
}

void Teacher::feedback()
{
    cout << "Feedback System Active." << endl;
}

Teacher::~Teacher()
{
    if (courses != nullptr)
        delete[] courses;
}