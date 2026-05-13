#include "Assignment.h"

Assignment::Assignment(float rs, float ms, float w) : Assessment(rs, ms, w) {}

float Assignment::getWeightedScore()
{
    if (maxScore == 0)
        return 0;
    return (rawScore / maxScore) * weightage;
}