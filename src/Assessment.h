#ifndef ASSESSMENT_H
#define ASSESSMENT_H

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

    void setRawScore(float rs) { rawScore = rs; }
    float getRawScore() const { return rawScore; }
    float getMaxScore() const { return maxScore; }
    float getWeightage() const { return weightage; }
};
#endif