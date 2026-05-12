#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include "Section.h"
#include "Venue.h"

class Scheduler
{
    vector<Section *> sections;
    vector<Venue *> venues;

public:
    Scheduler();
    void assignVenues();
    void conflictSolver();
    ~Scheduler();
};
#endif