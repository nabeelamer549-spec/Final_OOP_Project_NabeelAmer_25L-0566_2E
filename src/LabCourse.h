#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

using namespace std;

class LabCourse : public Course
{
public:
    LabCourse(string cid = " ", string tid = " ");
    void calculateFinalGrade() override;
    int getExamDuration() override;
};

#endif