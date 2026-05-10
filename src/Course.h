#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Course
{
protected:
    string courseID;
    string teacherID;
    vector<Student *> enrolledStudents;

public:
    Course(string cid = " ", string tid = " ");
    virtual void calculateFinalGrade() = 0;
    virtual int getExamDuration() = 0;
    virtual ~Course();
};

#endif