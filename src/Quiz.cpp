#include "Quiz.h"

Quiz::Quiz(float rs, float ms, float w) : Assessment(rs, ms, w) {}

float Quiz::getWeightedScore()
{
    return (rawScore / maxScore) * weightage;
}