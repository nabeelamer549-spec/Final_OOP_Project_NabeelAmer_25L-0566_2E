#ifndef LABCOURSE_H
#define LABCOURSE_H
#include "Course.h"

class LabCourse : public Course
{
public:
    LabCourse(string cid = "", string title = "", string tid = "");
    void calcGrade(string studentID) override;
    int getExamHours() override;
};
#endif