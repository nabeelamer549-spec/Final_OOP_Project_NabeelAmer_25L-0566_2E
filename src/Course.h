#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include "Student.h"
#include "Assessment.h"

class Course
{
protected:
    string CourseID;
    string TeacherID;
    vector<Student *> enrolledStudents;
    Assessment **assessments;
    int assessmentCount;
    int maxAssessments;

public:
    Course(string cid = " ", string tid = " ");
    virtual void calculateFinalGrade() = 0;
    virtual int getExamDuration() = 0;
    virtual ~Course();
};
#endif