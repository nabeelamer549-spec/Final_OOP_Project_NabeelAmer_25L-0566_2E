#ifndef VENUE_H
#define VENUE_H

#include <string>

using namespace std;

class Venue
{
    string roomID;
    int capacity;
    bool hasComputers;

public:
    Venue(string rid = " ", int cap = 0, bool computers = false);
    string getRoomID() const;
    int getCapacity() const;
};

#endif