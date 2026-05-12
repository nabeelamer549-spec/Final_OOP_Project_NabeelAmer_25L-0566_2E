#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <fstream>

using namespace std;

class DatabaseManager
{
public:
    DatabaseManager();
    virtual void saveData(string filename);
    virtual void loadData(string filename);
    virtual ~DatabaseManager();
};

#endif