#ifndef TEACHER_H
#define TEACHER_H
#include "AcademicEntity.h"

class Teacher : public AcademicEntity
{
private:
    int ratings[100];
    int ratingCount;
    float avgRating;
    float ratingSum;
    string coursesTeaching[20];
    int courseCount;

public:
    Teacher(string id = "", string n = "", string e = "");
    ~Teacher();
    void addRating(int r);
    float getAvgRating() const;
    void addCourse(string courseID);
    void displayProfile() const override;
    void saveToFile();
};
#endif