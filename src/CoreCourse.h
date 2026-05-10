#ifndef CORECOURSE_H
#define CORECOURSE_H

#include "Course.h"

using namespace std;

class CoreCourse : public Course
{
public:
    CoreCourse(string cid = " ", string tid = " ");
    void calculateFinalGrade() override;
    int getExamDuration() override;
};

#endif