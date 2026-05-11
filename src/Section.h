#ifndef SECTION_H
#define SECTION_H

#include <string>
#include "Course.h"
#include "Teacher.h"
#include "Venue.h"

using namespace std;

class Section
{
    string sectionID;
    Course *course;
    Teacher *teacher;
    Venue *venue;
    int timeSlot;

public:
    Section(string sid = " ", Course *c = nullptr, Teacher *t = nullptr, Venue *v = nullptr, int slot = 0);
    int getTimeSlot() const;
    Venue *getVenue() const;
};

#endif