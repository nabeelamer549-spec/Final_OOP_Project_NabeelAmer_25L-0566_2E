#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "Assessment.h"

using namespace std;

class Course
{
protected:
    string courseID;
    string title;
    string teacherID;
    string type;
    string enrolledStudents[100];
    int enrollmentCount;
    Assessment *assessments[50];
    int assessmentCount;
    float examWeight;
    float assignmentWeight;
    float quizWeight;

public:
    Course(string cid = "", string t = "", string tid = "", string typ = "");
    virtual ~Course();
    virtual void calcGrade(string studentID) = 0;
    virtual int getExamHours() = 0;

    void addAssessment(Assessment *a);
    float getStudentScore(string studentID);
    void enroll(string studentID);
    bool isEnrolled(string studentID);
    void loadWeights();

    string getID() const { return courseID; }
    string getTitle() const { return title; }
    string getType() const { return type; }
    string getTeacherID() const { return teacherID; }
};
#endif