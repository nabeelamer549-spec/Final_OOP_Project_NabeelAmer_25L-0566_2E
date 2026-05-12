#ifndef EXAM_H
#define EXAM_H
#include "Assessment.h"

class Exam : public Assessment
{
public:
    Exam(float rs = 0, float ms = 0, float w = 0);
    float getWeightedScore() override;
};
#endif