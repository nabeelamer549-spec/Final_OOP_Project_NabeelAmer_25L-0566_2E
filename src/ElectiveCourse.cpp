#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(string cid, string tid) : Course(cid, tid)
{
}

void ElectiveCourse::calculateFinalGrade()
{
}

int ElectiveCourse::getExamDuration()
{
    return 2;
}