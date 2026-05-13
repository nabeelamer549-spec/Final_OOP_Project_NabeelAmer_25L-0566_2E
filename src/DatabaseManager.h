#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DatabaseManager
{
public:
    DatabaseManager();
    void addRecord(string filename, string record);
    void viewAll(string filename);
    string getField(string line, int index);

    int getVenueCap(string vid);
    bool venueHasPCs(string vid);
    string getCourseType(string cid);
    bool checkConflict(string studentID, string timeSlot);
    void inputMarks(string secID);

    int countStudentsInSection(string secID);
    void addStudentToSection(string studentID, string secID);
};
#endif