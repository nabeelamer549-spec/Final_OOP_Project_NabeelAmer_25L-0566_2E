#include "Course.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

Course::Course(string cid, string t, string tid, string typ)
{
    courseID = cid;
    title = t;
    teacherID = tid;
    type = typ;
    enrollmentCount = 0;
    assessmentCount = 0;
    examWeight = assignmentWeight = quizWeight = 0;
    loadWeights();
}

Course::~Course()
{
    for (int i = 0; i < assessmentCount; i++)
    {
        delete assessments[i];
    }
}

void Course::loadWeights()
{
    ifstream file("weightages.txt");
    string line;

    while (getline(file, line))
    {
        size_t pos1 = line.find('|');
        string courseType = line.substr(0, pos1);

        if (courseType == type)
        {
            size_t pos2 = line.find('|', pos1 + 1);
            string examP = line.substr(pos1 + 1, pos2 - pos1 - 1);

            size_t pos3 = line.find('|', pos2 + 1);
            string assignP = line.substr(pos2 + 1, pos3 - pos2 - 1);

            string quizP = line.substr(pos3 + 1);

            examWeight = atof(examP.c_str()) / 100.0;
            assignmentWeight = atof(assignP.c_str()) / 100.0;
            quizWeight = atof(quizP.c_str()) / 100.0;
            break;
        }
    }
    file.close();
}

void Course::addAssessment(Assessment *a)
{
    if (assessmentCount < 50)
    {
        assessments[assessmentCount] = a;
        assessmentCount++;
    }
}

float Course::getStudentScore(string studentID)
{
    if (!isEnrolled(studentID))
        return 0;

    float total = 0;
    for (int i = 0; i < assessmentCount; i++)
    {
        total += assessments[i]->getWeightedScore();
    }
    return total;
}

void Course::enroll(string studentID)
{
    if (enrollmentCount < 100 && !isEnrolled(studentID))
    {
        enrolledStudents[enrollmentCount] = studentID;
        enrollmentCount++;
    }
}

bool Course::isEnrolled(string studentID)
{
    for (int i = 0; i < enrollmentCount; i++)
    {
        if (enrolledStudents[i] == studentID)
            return true;
    }
    return false;
}