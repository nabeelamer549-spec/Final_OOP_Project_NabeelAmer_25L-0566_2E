#ifndef ACADEMICENTITY_H
#define ACADEMICENTITY_H

#include <string>
#include <iostream>
using namespace std;

class AcademicEntity
{
    string id;
    string name;
    string email;

    AcademicEntity(string nid = " ", string nname = " ", string nemail = " ")
    {
    }
    virtual void displayProfile() = 0;
};

#endif