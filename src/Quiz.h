#ifndef QUIZ_H
#define QUIZ_H
#include "Assessment.h"

class Quiz : public Assessment
{
public:
    Quiz(float rs = 0, float ms = 0, float w = 0);
    float getWeightedScore() override;
};
#endif