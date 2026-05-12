#include "Scheduler.h"
#include <iostream>

Scheduler::Scheduler() {}

void Scheduler::conflictSolver()
{
    for (int i = 0; i < sections.size(); i++)
    {
        for (int j = i + 1; j < sections.size(); j++)
        {
            if (sections[i]->getTimeSlot() == sections[j]->getTimeSlot() &&
                sections[i]->getVenue() == sections[j]->getVenue())
            {
                cout << "Conflict: Venue " << sections[i]->getVenue()->getRoomID() << " is double-booked." << endl;
            }
        }
    }
}

Scheduler::~Scheduler() {}