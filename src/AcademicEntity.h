#ifndef ACADEMICENTITY_H
#define ACADEMICENTITY_H
#include <string>
using namespace std;

class AcademicEntity
{
protected:
    string ID;
    string name;
    string email;
    string file_path;

public:
    AcademicEntity(string id = " ", string n = " ", string e = " ", string fp = " ");
    virtual void displayProfile() const = 0;
    virtual ~AcademicEntity();
};
#endif