#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <iostream>
#include "AcademicEntity.h"
#include "DatabaseManager.h"
using namespace std;

class Teacher : public AcademicEntity, DatabaseManager
{
    string id;
    string name;
    string email;
    float avg;
    string *courses;
    int size;

public:
    Teacher(string nid = " ", string nname = " ", string nemail = " ", string *ncourses, int nsize = 0) : AcademicEntity(nid, nname, nemail)
    {
    }
    void feedback()
    {
    }
    ~Teacher()
    {
    }
};

#endif