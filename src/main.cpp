#include <iostream>
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "CoreCourse.h"
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
    LabCourse *programmingLab = new LabCourse("CS1002", "T101");
    Venue *normalRoom = new Venue("L1", 50, false);
    Venue *computerLab = new Venue("CS-Lab1", 40, true);

    cout << "Room L1 valid for Lab? " << (normalRoom->getCompStatus() ? "Yes" : "No (Needs Computers)") << endl;
    cout << "Room CS-Lab1 valid for Lab? " << (computerLab->getCompStatus() ? "Yes" : "No") << endl;

    cout << "\n--- SCENARIO 4: The 'Big Red Button' (Polymorphic Grading) ---" << endl;

    Exam *e1 = new Exam(45, 50, 50.0);
    cout << "Weighted Score for Exam: " << e1->getWeightedScore() << "%" << endl;

    cout << "\n--- SCENARIO 5: Teacher Feedback System ---" << endl;
    string subjects[] = {"OOP", "Calculus"};
    Teacher *prof = new Teacher("T001", "Dr. Amer", "amer@fast.edu", subjects, 2);
    prof->feedback();
    cout << "Feedback system initialized for Teacher ID: T001" << endl;

    // Cleanup
    delete scholar;
    delete ex;
    delete programmingLab;
    delete normalRoom;
    delete computerLab;
    delete e1;
    delete prof;

    return 0;
}