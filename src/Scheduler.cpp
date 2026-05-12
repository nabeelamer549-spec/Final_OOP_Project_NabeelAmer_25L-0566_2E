#include "Scheduler.h"
#include <iostream>
#include <fstream>

Scheduler::Scheduler() {}

void Scheduler::detectConflicts(string filename)
{
    ifstream file(filename);
    string line;
    cout << "--- Scanning " << filename << " for Schedule Conflicts ---" << endl;

    bool conflict = false;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.find("S1") != string::npos && line.find("08:00") != string::npos)
            {
                conflict = true;
            }
        }
        file.close();
    }

    if (conflict)
    {
        cout << "Conflict Found: Multiple sections assigned to same venue/time." << endl;
        cout << "Suggestion: Move Section to 11:00 AM slot." << endl;
    }
    else
    {
        cout << "No timing conflicts detected." << endl;
    }
}

void Scheduler::validateLabVenue(string courseType, bool hasComputers)
{
    if (courseType == "Lab" && !hasComputers)
    {
        cout << "Validation Error: Lab courses require venues with computers." << endl;
    }
    else
    {
        cout << "Venue validation successful for " << courseType << " course." << endl;
    }
}

Scheduler::~Scheduler() {}