#include "Venue.h"
#include <iostream>

Venue::Venue(string rid, int cap, bool comp)
{
    roomID = rid;
    capacity = cap;
    hasComputers = comp;
}

void Venue::show() const
{
    cout << "Room: " << roomID << " | Capacity: " << capacity
         << " | Computers: " << (hasComputers ? "Yes" : "No") << endl;
}