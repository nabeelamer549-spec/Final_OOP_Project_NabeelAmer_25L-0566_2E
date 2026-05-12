#include "Venue.h"

Venue::Venue(string rid, int cap, bool comp)
{
    roomID = rid;
    capacity = cap;
    hasComputers = comp;
}

string Venue::getRoomID() const { return roomID; }
int Venue::getCapacity() const { return capacity; }
bool Venue::getCompStatus() const { return hasComputers; }