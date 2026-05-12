#include <iostream>
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "LabCourse.h"
#include "Venue.h"
#include "Exam.h"
#include "Teacher.h"

using namespace std;

int main()
{
    cout << "--- SCENARIO 1: Probation Logic ---" << endl;
    ScholarshipStudent *scholar = new ScholarshipStudent("24L-0001", "Nabeel", "n@fast.edu", 2.5);
    scholar->calculateGPA();
    scholar->displayProfile();

    cout << "\n--- SCENARIO 2: Exchange Student Pass/Fail ---" << endl;
    ExchangeStudent *ex = new ExchangeStudent("24L-9999", "Peer", "p@fast.edu", 3.8);
    ex->calculateGPA();
    ex->viewTranscript();

    cout << "\n--- SCENARIO 3: Lab Course Venue Check ---" << endl;
    Venue *normalRoom = new Venue("L1", 50, false);
    cout << "Room L1 valid for Lab? " << (normalRoom->getCompStatus() ? "Yes" : "No") << endl;

    cout << "\n--- SCENARIO 4: Teacher System ---" << endl;
    string subs[] = {"OOP", "Calculus"};
    Teacher *prof = new Teacher("T001", "Dr. Amer", "amer@fast.edu", subs, 2);
    prof->feedback();

    delete scholar;
    delete ex;
    delete normalRoom;
    delete prof;
    return 0;
}