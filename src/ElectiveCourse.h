#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"

class ElectiveCourse : public Course
{
public:
    ElectiveCourse(string cid = "", string title = "", string tid = "");
    void calcGrade(string studentID) override;
    int getExamHours() override;
};
#endif