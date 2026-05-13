#include "Student.h"
#include <iostream>

Student::Student(string id, string n, string e, float g) : AcademicEntity(id, n, e, "Students.txt")
{
    gpa = g;
    status = "Active";
    courseCount = 0;
}

Student::~Student() {}

void Student::displayProfile() const
{
    cout << "ID: " << ID << " | Name: " << name << " | GPA: " << gpa << " | Status: " << status << endl;
}

void Student::addCourse(string courseID, float grade)
{
    if (courseCount < 10)
    {
        courseIDs[courseCount] = courseID;
        courseGrades[courseCount] = grade;
        courseCount++;
    }
}