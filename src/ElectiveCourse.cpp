#include "ElectiveCourse.h"
#include <iostream>

ElectiveCourse::ElectiveCourse(string cid, string title, string tid)
    : Course(cid, title, tid, "Elective") {}

void ElectiveCourse::calcGrade(string studentID)
{
    float score = getStudentScore(studentID);
    cout << "Elective Course: " << studentID << " scored " << score << "%" << endl;
}

int ElectiveCourse::getExamHours()
{
    return 2;
}