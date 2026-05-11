#include "Section.h"

Section::Section(string sid, Course *c, Teacher *t, Venue *v, int slot)
{
    sectionID = sid;
    course = c;
    teacher = t;
    venue = v;
    timeSlot = slot;
}
int Section::getTimeSlot() const { return timeSlot; }
Venue *Section::getVenue() const { return venue; }