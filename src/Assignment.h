#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include "Assessment.h"

class Assignment : public Assessment
{
public:
    Assignment(float rs = 0, float ms = 0, float w = 0);
    float getWeightedScore() override;
};
#endif