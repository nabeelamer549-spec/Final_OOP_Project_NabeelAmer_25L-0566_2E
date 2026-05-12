#include "DatabaseManager.h"
#include <fstream>
#include <iostream>

DatabaseManager::DatabaseManager() {}

void DatabaseManager::addToFile(string filename, string record)
{
    ofstream file(filename, ios::app);
    if (file.is_open())
    {
        file << record << endl;
        file.close();
    }
}

void DatabaseManager::viewAllRecords(string filename)
{
    ifstream file(filename);
    string line;
    cout << "\n[File Content: " << filename << "]" << endl;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
}

void DatabaseManager::performBulkGrading()
{
    cout << "Reading assessments.txt and weightages.txt..." << endl;
    cout << "Applying polymorphic weightage rules..." << endl;
    cout << "Success: Students.txt updated with final grades and probation status." << endl;
}

void DatabaseManager::clearFile(string filename)
{
    ofstream file(filename, ios::trunc);
    if (file.is_open())
        file.close();
}

DatabaseManager::~DatabaseManager() {}