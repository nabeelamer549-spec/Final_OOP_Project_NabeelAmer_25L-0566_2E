#include "Course.h"
Course::Course(string cid, string tid)
{
    CourseID = cid;
    TeacherID = tid;
    assessmentCount = 0;
    assessments = new Assessment *[10];
}
Course::~Course()
{
    for (int i = 0; i < assessmentCount; i++)
        delete assessments[i];
    delete[] assessments;
}