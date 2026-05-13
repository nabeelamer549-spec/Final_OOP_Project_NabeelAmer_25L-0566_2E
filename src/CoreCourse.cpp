#include "CoreCourse.h"
#include <iostream>

CoreCourse::CoreCourse(string cid, string title, string tid)
    : Course(cid, title, tid, "Core") {}

void CoreCourse::calcGrade(string studentID)
{
    float score = getStudentScore(studentID);
    cout << "Core Course: " << studentID << " scored " << score << "%" << endl;
}

int CoreCourse::getExamHours()
{
    return 3;
}