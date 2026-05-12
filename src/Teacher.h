#ifndef TEACHER_H
#define TEACHER_H

#include "AcademicEntity.h"
#include "DatabaseManager.h"

class Teacher : public AcademicEntity, public DatabaseManager
{
private:
    string *courses;
    int size;
    float avgFeedback;

public:
    Teacher(string id = " ", string n = " ", string e = " ", string *c = nullptr, int s = 0);
    void displayProfile() const override;
    void addFeedback(int rating);
    void feedback();
    ~Teacher();
};

#endif