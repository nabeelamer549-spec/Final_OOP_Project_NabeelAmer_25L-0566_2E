#include "Scheduler.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void Scheduler::runAudit()
{
    cout << "\n========== LOGISTICS AUDIT ==========" << endl;

    ifstream file("sections.txt");
    string line;
    bool problem = false;

    while (getline(file, line))
    {
        string secID = db.getField(line, 0);
        string courseID = db.getField(line, 1);
        string teacherID = db.getField(line, 2);
        string venueID = db.getField(line, 3);
        string timeSlot = db.getField(line, 4);
        string studentList = db.getField(line, 5);

        string courseType = db.getCourseType(courseID);
        bool hasPCs = db.venueHasPCs(venueID);

        if (courseType == "Lab" && !hasPCs)
        {
            cout << "PROBLEM: Section " << secID << " (Lab) in " << venueID << " has no computers!" << endl;
            problem = true;
        }

        int capacity = db.getVenueCap(venueID);

        int enrolled = 0;
        if (studentList != "")
        {
            enrolled = 1;
            for (int i = 0; i < studentList.length(); i++)
            {
                if (studentList[i] == ',')
                    enrolled++;
            }
        }

        if (enrolled > capacity)
        {
            cout << "Section " << secID << " has " << enrolled
                 << " students but capacity is " << capacity << endl;
            cout << "SPLITTING into multiple venues..." << endl;

            string venues[10];
            int capacities[10];
            int venueCount = 0;

            ifstream vfile("Venues.txt");
            string vline;
            while (getline(vfile, vline) && venueCount < 10)
            {
                venues[venueCount] = db.getField(vline, 0);
                capacities[venueCount] = atoi(db.getField(vline, 1).c_str());
                venueCount++;
            }
            vfile.close();

            string allTimes[] = {"08:00", "10:00", "12:00", "14:00", "16:00"};
            int remaining = enrolled;
            int timeIdx = 0;

            string sections[100];
            int secCount = 0;
            ifstream sfile("sections.txt");
            string sl;
            while (getline(sfile, sl))
            {
                if (db.getField(sl, 0) != secID)
                {
                    sections[secCount] = sl;
                    secCount++;
                }
            }
            sfile.close();

            string students[100];
            int stuCount = 0;
            if (studentList != "")
            {
                size_t pos = 0;
                string temp = studentList;
                while (pos < temp.length())
                {
                    size_t comma = temp.find(',', pos);
                    if (comma == string::npos)
                    {
                        students[stuCount++] = temp.substr(pos);
                        pos = temp.length();
                    }
                    else
                    {
                        students[stuCount++] = temp.substr(pos, comma - pos);
                        pos = comma + 1;
                    }
                }
            }

            ofstream outFile("sections.txt");
            for (int i = 0; i < secCount; i++)
            {
                outFile << sections[i] << endl;
            }

            int start = 0;
            for (int i = 0; i < venueCount && remaining > 0; i++)
            {
                int take = (capacities[i] < remaining) ? capacities[i] : remaining;
                string newList = "";
                for (int j = start; j < start + take && j < stuCount; j++)
                {
                    if (newList == "")
                        newList = students[j];
                    else
                        newList = newList + "," + students[j];
                }
                outFile << secID << "_" << (i + 1) << "|" << courseID << "|"
                        << teacherID << "|" << venues[i] << "|"
                        << allTimes[timeIdx % 5] << "|" << newList << endl;
                remaining -= take;
                start += take;
                timeIdx++;
            }
            outFile.close();

            cout << "Section split into " << venueCount << " venues!" << endl;
            problem = true;
        }
    }
    file.close();

    if (!problem)
    {
        cout << "All checks passed!" << endl;
    }

    fixConflicts();
    saveExamSchedule();
    displaySchedule();
}

void Scheduler::fixConflicts()
{
    cout << "\nChecking for conflicts..." << endl;

    ifstream file("sections.txt");
    string line;
    string schedule[100][3];
    int count = 0;

    while (getline(file, line))
    {
        string venue = db.getField(line, 3);
        string time = db.getField(line, 4);
        string sec = db.getField(line, 0);

        for (int i = 0; i < count; i++)
        {
            if (schedule[i][0] == venue && schedule[i][1] == time)
            {
                cout << "CONFLICT: " << sec << " and " << schedule[i][2]
                     << " both in " << venue << " at " << time << endl;

                string times[] = {"08:00", "10:00", "12:00", "14:00", "16:00"};
                for (int j = 0; j < 5; j++)
                {
                    bool free = true;
                    ifstream check("sections.txt");
                    string cl;
                    while (getline(check, cl))
                    {
                        if (db.getField(cl, 3) == venue && db.getField(cl, 4) == times[j])
                        {
                            free = false;
                            break;
                        }
                    }
                    check.close();
                    if (free)
                    {
                        cout << "  Suggested: " << times[j] << " for " << sec << endl;
                        break;
                    }
                }
            }
        }
        schedule[count][0] = venue;
        schedule[count][1] = time;
        schedule[count][2] = sec;
        count++;
    }
    file.close();
}

void Scheduler::saveExamSchedule()
{
    ofstream outFile("exam_schedule.txt");
    outFile << "========================================" << endl;
    outFile << "   FAST UNIVERSITY EXAMINATION SCHEDULE" << endl;
    outFile << "========================================" << endl;
    outFile << "Section | Course | Venue | Time | Duration" << endl;
    outFile << "----------------------------------------" << endl;

    ifstream file("sections.txt");
    string line;

    while (getline(file, line))
    {
        string sec = db.getField(line, 0);
        string course = db.getField(line, 1);
        string venue = db.getField(line, 3);
        string time = db.getField(line, 4);
        string type = db.getCourseType(course);

        int hours = 0;
        if (type == "Core")
            hours = 3;
        else if (type == "Elective")
            hours = 2;

        if (hours > 0)
        {
            outFile << sec << " | " << course << " | " << venue << " | " << time << " | " << hours << " hours" << endl;
        }
    }
    file.close();
    outFile.close();

    cout << "\nExam schedule saved to exam_schedule.txt" << endl;
}

void Scheduler::displaySchedule()
{
    cout << "\n=== EXAM SCHEDULE ===" << endl;
    cout << "Section | Course | Venue | Time | Duration" << endl;
    cout << "----------------------------------------" << endl;

    ifstream file("sections.txt");
    string line;

    while (getline(file, line))
    {
        string sec = db.getField(line, 0);
        string course = db.getField(line, 1);
        string venue = db.getField(line, 3);
        string time = db.getField(line, 4);
        string type = db.getCourseType(course);

        int hours = 0;
        if (type == "Core")
            hours = 3;
        else if (type == "Elective")
            hours = 2;

        if (hours > 0)
        {
            cout << sec << " | " << course << " | " << venue << " | " << time << " | " << hours << " hours" << endl;
        }
    }
    file.close();
}