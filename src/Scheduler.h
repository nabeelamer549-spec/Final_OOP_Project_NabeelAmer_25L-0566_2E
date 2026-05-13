#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "DatabaseManager.h"

class Scheduler
{
private:
    DatabaseManager db;

public:
    void runAudit();
    void fixConflicts();
    void displaySchedule();
    void saveExamSchedule();
};
#endif