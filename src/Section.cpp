#include "Section.h"
#include <iostream>

Section::Section(string sid, string cid, string tid, string vid, string time)
{
    secID = sid;
    courseID = cid;
    teacherID = tid;
    venueID = vid;
    timeSlot = time;
    studentCount = 0;
}

Section::~Section() {}

void Section::addStudent(string studentID)
{
    if (studentCount < 100 && !hasStudent(studentID))
    {
        students[studentCount] = studentID;
        studentCount++;
    }
}

bool Section::hasStudent(string studentID)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i] == studentID)
            return true;
    }
    return false;
}

void Section::display() const
{
    cout << "Section " << secID << " | Course: " << courseID
         << " | Time: " << timeSlot << " | Students: " << studentCount << endl;
}