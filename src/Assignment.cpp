#include "Assignment.h"

Assignment::Assignment(float rs, float ms, float w) : Assessment(rs, ms, w) {}

float Assignment::getWeightedScore()
{
    return (rawScore / maxScore) * weightage;
}