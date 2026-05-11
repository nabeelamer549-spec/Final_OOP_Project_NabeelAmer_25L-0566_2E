#include "Venue.h"

Venue::Venue(string rid, int cap, bool computers)
{
    roomID = rid;
    capacity = cap;
    hasComputers = computers;
}
string Venue::getRoomID() const { return roomID; }
int Venue::getCapacity() const { return capacity; }