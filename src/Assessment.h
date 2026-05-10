#ifndef ASSESSMENT_H
#define ASSESSMENT_H

using namespace std;

class Assessment
{
protected:
    float rawScore;
    float maxScore;
    float weightage;

public:
    Assessment(float rs = 0, float ms = 0, float w = 0);
    virtual float getWeightedScore() = 0;
    virtual ~Assessment();
};

#endif