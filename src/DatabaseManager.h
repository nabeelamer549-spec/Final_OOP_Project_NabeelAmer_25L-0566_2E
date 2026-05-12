#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <vector>

using namespace std;

class DatabaseManager
{
public:
    DatabaseManager();
    void addToFile(string filename, string record);
    void viewAllRecords(string filename);
    void clearFile(string filename);
    virtual ~DatabaseManager();
};

#endif