#ifndef SECTION_H
#define SECTION_H
#include <string>
using namespace std;

class Section
{
private:
    string secID;
    string courseID;
    string teacherID;
    string venueID;
    string timeSlot;
    string students[100];
    int studentCount;

public:
    Section(string sid = "", string cid = "", string tid = "", string vid = "", string time = "");
    ~Section();

    string getSecID() const { return secID; }
    string getCourseID() const { return courseID; }
    string getVenueID() const { return venueID; }
    string getTime() const { return timeSlot; }
    void addStudent(string studentID);
    bool hasStudent(string studentID);
    int getCount() const { return studentCount; }
    void display() const;
};
#endif