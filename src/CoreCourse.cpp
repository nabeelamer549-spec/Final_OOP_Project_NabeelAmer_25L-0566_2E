#include "CoreCourse.h"

CoreCourse::CoreCourse(string cid, string tid) : Course(cid, tid)
{
}

void CoreCourse::calculateFinalGrade()
{
}

int CoreCourse::getExamDuration()
{
    return 3;
}