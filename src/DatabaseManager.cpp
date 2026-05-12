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
    else
    {
        cout << "Error: Could not open " << filename << endl;
    }
}

void DatabaseManager::viewAllRecords(string filename)
{
    ifstream file(filename);
    string line;
    cout << "--- Reading: " << filename << " ---" << endl;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "File not found." << endl;
    }
}

void DatabaseManager::clearFile(string filename)
{
    ofstream file(filename, ios::trunc);
    if (file.is_open())
    {
        file.close();
    }
}

DatabaseManager::~DatabaseManager() {}