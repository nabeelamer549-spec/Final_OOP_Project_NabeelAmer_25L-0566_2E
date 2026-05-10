#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"

using namespace std;

class ElectiveCourse : public Course
{
public:
    ElectiveCourse(string cid = " ", string tid = " ");
    void calculateFinalGrade() override;
    int getExamDuration() override;
};

#endif