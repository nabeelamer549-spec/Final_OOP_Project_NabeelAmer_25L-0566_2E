#include "Exam.h"

Exam::Exam(float rs, float ms, float w) : Assessment(rs, ms, w) {}

float Exam::getWeightedScore()
{
    return (rawScore / maxScore) * weightage;
}