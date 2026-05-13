#include "Quiz.h"

Quiz::Quiz(float rs, float ms, float w) : Assessment(rs, ms, w) {}

float Quiz::getWeightedScore()
{
    if (maxScore == 0)
        return 0;
    return (rawScore / maxScore) * weightage;
}