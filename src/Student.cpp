#include "Student.h"

Student::Student(string nid, string nname, string nemail, float ngpa) : AcademicEntity(nid, nname, nemail)
{
    id = nid;
    name = nname;
    email = nemail;
    gpa = ngpa;
    status = "Active";
}

Student::~Student()
{
}