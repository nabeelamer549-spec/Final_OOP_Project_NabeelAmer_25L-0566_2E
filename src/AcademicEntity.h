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
    AcademicEntity(string nid = " ", string nname = " ", string nemail = " ");
    virtual ~AcademicEntity();
    virtual void displayProfile() const = 0;
    string getId() const;
    string getName() const;
};

#endif