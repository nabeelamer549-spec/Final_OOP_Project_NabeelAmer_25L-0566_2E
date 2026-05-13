#include "Exam.h"

Exam::Exam(float rs, float ms, float w) : Assessment(rs, ms, w) {}

float Exam::getWeightedScore()
{
    if (maxScore == 0)
        return 0;
    return (rawScore / maxScore) * weightage;
}