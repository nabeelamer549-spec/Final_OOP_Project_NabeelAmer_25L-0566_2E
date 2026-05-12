#ifndef CORECOURSE_H
#define CORECOURSE_H
#include "Course.h"

class CoreCourse : public Course
{
public:
    CoreCourse(string cid = " ", string tid = " ");
    void calculateFinalGrade() override;
    int getExamDuration() override;
};
#endif