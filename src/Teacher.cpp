#include <iostream>
#include <string>
#include <cstring>
#include "Teacher.h"

Teacher::Teacher(string nid = " ", string nname = " ", string nemail = " ", string *ncourses, int nsize = 0) : AcademicEntity(nid, nname, nemail)
{
    id = nid;
    name = nname;
    email = nemail;
    avg = 0;
    size = nsize;
    courses = new string[size];

    if (ncourses != nullptr)
    {
        for (int i = 0; i < size; i++)
        {
            courses[i] = ncourses[i];
        }
    }
}
Teacher::~Teacher()
{
    delete[] courses;
}
void Teacher::feedback()
{
}