#ifndef STUDENT_H
#define STUDENT_H
#include "AcademicEntity.h"

class Student : public AcademicEntity
{
protected:
    float gpa;
    string status;
    string courseIDs[10];
    float courseGrades[10];
    int courseCount;

public:
    Student(string id = "", string n = "", string e = "", float g = 0.0);
    virtual ~Student();
    virtual void calculateGPA() = 0;
    virtual void viewTranscript() const = 0;
    void displayProfile() const override;

    float getGPA() const { return gpa; }
    string getStatus() const { return status; }
    void addCourse(string courseID, float grade);
    int getCourseCount() const { return courseCount; }
};
#endif