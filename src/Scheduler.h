#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <vector>

using namespace std;

class Scheduler
{
public:
    Scheduler();
    void detectConflicts(string filename);
    void validateLabVenue(string courseType, bool hasComputers);
    ~Scheduler();
};

#endif