#include "LabCourse.h"
#include <iostream>

LabCourse::LabCourse(string cid, string title, string tid)
    : Course(cid, title, tid, "Lab") {}

void LabCourse::calcGrade(string studentID)
{
    float score = getStudentScore(studentID);
    cout << "Lab Course: " << studentID << " scored " << score << "% (No exam)" << endl;
}

int LabCourse::getExamHours()
{
    return 0;
}