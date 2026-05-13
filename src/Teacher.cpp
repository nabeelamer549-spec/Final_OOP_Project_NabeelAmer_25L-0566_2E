#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

Teacher::Teacher(string id, string n, string e)
    : AcademicEntity(id, n, e, "Teachers.txt")
{
    ratingCount = 0;
    avgRating = 0;
    ratingSum = 0;
    courseCount = 0;

    ifstream file("Teachers.txt");
    string line;
    while (getline(file, line))
    {
        size_t pos = line.find('|');
        string tid = line.substr(0, pos);

        if (tid == ID)
        {
            string temp = line;
            for (int i = 0; i < 3; i++)
            {
                size_t pipePos = temp.find('|');
                temp = temp.substr(pipePos + 1);
            }
            size_t pipePos = temp.find('|');
            avgRating = atof(temp.substr(0, pipePos).c_str());

            temp = temp.substr(pipePos + 1);
            pipePos = temp.find('|');
            ratingCount = atoi(temp.substr(0, pipePos).c_str());

            ratingSum = avgRating * ratingCount;
            break;
        }
    }
    file.close();
}

Teacher::~Teacher() {}

void Teacher::addRating(int r)
{
    if (r >= 1 && r <= 5)
    {
        if (ratingCount < 100)
        {
            ratings[ratingCount] = r;
        }
        ratingCount++;
        ratingSum += r;
        avgRating = ratingSum / ratingCount;

        saveToFile();
        cout << "Rating added! New average: " << avgRating << " (from " << ratingCount << " ratings)" << endl;
    }
    else
    {
        cout << "Rating must be 1-5!" << endl;
    }
}

float Teacher::getAvgRating() const
{
    return avgRating;
}

void Teacher::addCourse(string courseID)
{
    if (courseCount < 20)
    {
        coursesTeaching[courseCount] = courseID;
        courseCount++;
    }
}

void Teacher::displayProfile() const
{
    cout << "Teacher: " << name << " (" << ID << ")" << endl;
    cout << "Average Rating: " << avgRating << " (from " << ratingCount << " students)" << endl;
}

void Teacher::saveToFile()
{
    string allLines[100];
    int lineCount = 0;

    ifstream file("Teachers.txt");
    string line;
    while (getline(file, line))
    {
        allLines[lineCount] = line;
        lineCount++;
    }
    file.close();

    ofstream outFile("Teachers.txt");
    bool updated = false;

    for (int i = 0; i < lineCount; i++)
    {
        size_t pos = allLines[i].find('|');
        string id = allLines[i].substr(0, pos);

        if (id == ID)
        {
            outFile << ID << "|" << name << "|" << email << "|"
                    << avgRating << "|" << ratingCount << "|" << ratingSum << endl;
            updated = true;
        }
        else
        {
            outFile << allLines[i] << endl;
        }
    }

    if (!updated)
    {
        outFile << ID << "|" << name << "|" << email << "|"
                << avgRating << "|" << ratingCount << "|" << ratingSum << endl;
    }
    outFile.close();
}