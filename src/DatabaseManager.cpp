#include "DatabaseManager.h"
#include <cstdlib>

DatabaseManager::DatabaseManager() {}

void DatabaseManager::addRecord(string filename, string record)
{
    ofstream file(filename, ios::app);
    if (file)
    {
        file << record << endl;
        file.close();
        cout << "Record added!" << endl;
    }
    else
    {
        cout << "Error opening file" << endl;
    }
}

void DatabaseManager::viewAll(string filename)
{
    ifstream file(filename);
    string line;
    if (!file)
    {
        cout << "Can't open " << filename << endl;
        return;
    }

    cout << "\n--- " << filename << " ---" << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

string DatabaseManager::getField(string line, int index)
{
    size_t start = 0;
    size_t end;

    for (int i = 0; i <= index; i++)
    {
        end = line.find('|', start);
        if (end == string::npos && i == index)
            return line.substr(start);
        if (i == index)
            return line.substr(start, end - start);
        start = end + 1;
    }
    return "";
}

int DatabaseManager::getVenueCap(string vid)
{
    ifstream file("Venues.txt");
    string line;
    while (getline(file, line))
    {
        if (getField(line, 0) == vid)
        {
            int cap = atoi(getField(line, 1).c_str());
            file.close();
            return cap;
        }
    }
    return 0;
}

bool DatabaseManager::venueHasPCs(string vid)
{
    ifstream file("Venues.txt");
    string line;
    while (getline(file, line))
    {
        if (getField(line, 0) == vid)
        {
            bool has = (getField(line, 2) == "1");
            file.close();
            return has;
        }
    }
    return false;
}

string DatabaseManager::getCourseType(string cid)
{
    ifstream file("Courses.txt");
    string line;
    while (getline(file, line))
    {
        if (getField(line, 0) == cid)
        {
            string type = getField(line, 3);
            file.close();
            return type;
        }
    }
    return "Core";
}

bool DatabaseManager::checkConflict(string studentID, string timeSlot)
{
    ifstream file("sections.txt");
    string line;

    while (getline(file, line))
    {
        string studentList = getField(line, 5);
        string sectionTime = getField(line, 4);

        if (sectionTime == timeSlot && studentList != "")
        {
            size_t pos = 0;
            string temp = studentList;
            while (pos < temp.length())
            {
                size_t comma = temp.find(',', pos);
                string sid;
                if (comma == string::npos)
                {
                    sid = temp.substr(pos);
                    pos = temp.length();
                }
                else
                {
                    sid = temp.substr(pos, comma - pos);
                    pos = comma + 1;
                }
                if (sid == studentID)
                {
                    file.close();
                    return true;
                }
            }
        }
    }
    file.close();
    return false;
}

void DatabaseManager::inputMarks(string secID)
{
    ifstream file("assessments.txt");
    string lines[100];
    int lineCount = 0;
    string line;

    cout << "\nEntering marks for Section " << secID << endl;

    while (getline(file, line))
    {
        if (getField(line, 0) == secID)
        {
            string type = getField(line, 1);
            float maxScore = atof(getField(line, 3).c_str());
            float rawScore;

            cout << type << " (max " << maxScore << "): ";
            cin >> rawScore;

            string updated = getField(line, 0) + "|" + getField(line, 1) + "|" + to_string(rawScore) + "|" + to_string(maxScore);
            lines[lineCount] = updated;
        }
        else
        {
            lines[lineCount] = line;
        }
        lineCount++;
    }
    file.close();

    ofstream outFile("assessments.txt");
    for (int i = 0; i < lineCount; i++)
    {
        outFile << lines[i] << endl;
    }
    outFile.close();

    cout << "Marks saved!" << endl;
}

int DatabaseManager::countStudentsInSection(string secID)
{
    ifstream file("sections.txt");
    string line;
    while (getline(file, line))
    {
        if (getField(line, 0) == secID)
        {
            string studentList = getField(line, 5);
            if (studentList == "")
            {
                file.close();
                return 0;
            }

            int count = 1;
            for (int i = 0; i < studentList.length(); i++)
            {
                if (studentList[i] == ',')
                    count++;
            }
            file.close();
            return count;
        }
    }
    file.close();
    return 0;
}

void DatabaseManager::addStudentToSection(string studentID, string secID)
{
    string lines[100];
    int lineCount = 0;
    ifstream file("sections.txt");
    string line;

    while (getline(file, line))
    {
        if (getField(line, 0) == secID)
        {
            string studentList = getField(line, 5);
            string newList;
            if (studentList == "")
            {
                newList = studentID;
            }
            else
            {
                newList = studentList + "," + studentID;
            }
            lines[lineCount] = getField(line, 0) + "|" + getField(line, 1) + "|" + getField(line, 2) + "|" + getField(line, 3) + "|" + getField(line, 4) + "|" + newList;
        }
        else
        {
            lines[lineCount] = line;
        }
        lineCount++;
    }
    file.close();

    ofstream outFile("sections.txt");
    for (int i = 0; i < lineCount; i++)
    {
        outFile << lines[i] << endl;
    }
    outFile.close();
}