#include <iostream>
#include <string>
#include <limits>
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "RegularStudent.h"
#include "Teacher.h"
#include "Venue.h"
#include "Scheduler.h"

using namespace std;

int main()
{
    DatabaseManager db;
    Scheduler academicOffice;
    int choice = 0;

    db.clearFile("Students.txt");
    db.clearFile("Teachers.txt");
    db.clearFile("weightages.txt");
    db.clearFile("Courses.txt");
    db.clearFile("Venues.txt");
    db.clearFile("sections.txt");
    db.clearFile("assessments.txt");

    db.addToFile("Students.txt", "24L-0001|Nabeel|Scholarship|2.5|Probation");
    db.addToFile("Students.txt", "24L-9999|Peer|Exchange|3.8|Pass");
    db.addToFile("Teachers.txt", "T001|Dr. Amer|4.8");
    db.addToFile("weightages.txt", "Core|50|25|25");
    db.addToFile("Courses.txt", "CS1002|OOP|T001|Core");
    db.addToFile("Venues.txt", "L1|50|0");
    db.addToFile("Venues.txt", "CS-Lab1|40|1");
    db.addToFile("sections.txt", "S1|CS1002|T001|L1|08:00-11:00");
    db.addToFile("assessments.txt", "S1|Exam|45|50");

    while (choice != 6)
    {
        cout << "\n========================================" << endl;
        cout << "    FAST ACADEMIC OFFICE SYSTEM (V1)    " << endl;
        cout << "========================================" << endl;
        cout << "1. View Database Records (CRUD - Read)" << endl;
        cout << "2. Register New Student (CRUD - Create)" << endl;
        cout << "3. The Big Red Button (Polymorphic Grading)" << endl;
        cout << "4. Run Conflict Solver (Scheduler Logic)" << endl;
        cout << "5. Teacher Feedback System (Rating/Avg)" << endl;
        cout << "6. Exit" << endl;
        cout << "Selection: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 6." << endl;
            continue;
        }

        if (choice == 1)
        {
            db.viewAllRecords("Students.txt");
            db.viewAllRecords("Teachers.txt");
            db.viewAllRecords("sections.txt");
            db.viewAllRecords("Venues.txt");
        }
        else if (choice == 2)
        {
            string id, name, email, type;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Type (Regular/Scholarship/Exchange): ";
            cin >> type;

            if (type != "Regular" && type != "Scholarship" && type != "Exchange")
            {
                cout << "Validation Error: Invalid Student Type." << endl;
            }
            else
            {
                string record = id + "|" + name + "|" + email + "|0.0|" + type;
                db.addToFile("Students.txt", record);
                cout << "Student registered successfully." << endl;
            }
        }
        else if (choice == 3)
        {
            db.performBulkGrading();
        }
        else if (choice == 4)
        {
            academicOffice.detectConflicts("sections.txt");
            academicOffice.validateLabVenue("Lab", false);
        }
        else if (choice == 5)
        {
            string s[] = {"OOP"};
            Teacher t("T001", "Dr. Amer", "amer@fast.edu", s, 1);
            int r;
            cout << "Submit rating for Dr. Amer (1-5): ";
            cin >> r;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Rating must be a number." << endl;
            }
            else
            {
                t.addFeedback(r);
            }
        }
        else if (choice == 6)
        {
            cout << "System shutting down. All data persisted to .txt files." << endl;
        }
        else
        {
            cout << "Invalid selection. Please try again." << endl;
        }
    }

    return 0;
}