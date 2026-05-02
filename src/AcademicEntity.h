#ifndef ACADEMICENTITY_H
#define ACADEMICENTITY_H

#include <string>
#include <iostream>
using namespace std;

class AcademicEntity
{
protected:
    string id;
    string name;
    string email;

public:
    AcademicEntity()
    {
    }

    AcademicEntity(string nid, string nname, string nemail)
    {
    }
    virtual void displayprofile() = 0;
};

#endif