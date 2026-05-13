#ifndef VENUE_H
#define VENUE_H
#include <string>
using namespace std;

class Venue
{
private:
    string roomID;
    int capacity;
    bool hasComputers;

public:
    Venue(string rid = "", int cap = 0, bool comp = false);
    string getID() const { return roomID; }
    int getCapacity() const { return capacity; }
    bool hasPCs() const { return hasComputers; }
    void show() const;
};
#endif