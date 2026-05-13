#ifndef CORECOURSE_H
#define CORECOURSE_H
#include "Course.h"

class CoreCourse : public Course
{
public:
    CoreCourse(string cid = "", string title = "", string tid = "");
    void calcGrade(string studentID) override;
    int getExamHours() override;
};
#endif