#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DatabaseManager.h"
#include "Scheduler.h"
#include "Teacher.h"
#include "RegularStudent.h"
#include "ScholarshipStudent.h"
#include "ExchangeStudent.h"
#include "CoreCourse.h"
#include "ElectiveCourse.h"
#include "LabCourse.h"

using namespace std;

DatabaseManager db;

void viewRecords();
void registerStudent();
void teacherFeedback();
void gradingSystem();
void runScheduler();
void polymorphismDemo();

int main()
{
    int choice;

    cout << "\n========================================" << endl;
    cout << "   FAST UNIVERSITY MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;

    do
    {
        cout << "\n1. View Records" << endl;
        cout << "2. Register Student" << endl;
        cout << "3. Teacher Feedback" << endl;
        cout << "4. Big Red Button (Grading)" << endl;
        cout << "5. Run Scheduler" << endl;
        cout << "6. Polymorphism Demo" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            viewRecords();
            break;
        case 2:
            registerStudent();
            break;
        case 3:
            teacherFeedback();
            break;
        case 4:
            gradingSystem();
            break;
        case 5:
            runScheduler();
            break;
        case 6:
            polymorphismDemo();
            break;
        case 7:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}

void viewRecords()
{
    int sub;
    cout << "\n1.Students 2.Teachers 3.Courses 4.Venues 5.Sections 6.Assessments: ";
    cin >> sub;

    switch (sub)
    {
    case 1:
        db.viewAll("Students.txt");
        break;
    case 2:
        db.viewAll("Teachers.txt");
        break;
    case 3:
        db.viewAll("Courses.txt");
        break;
    case 4:
        db.viewAll("Venues.txt");
        break;
    case 5:
        db.viewAll("sections.txt");
        break;
    case 6:
        db.viewAll("assessments.txt");
        break;
    default:
        cout << "Invalid" << endl;
    }
}

void registerStudent()
{
    cout << "\n=== SMART REGISTRATION ===" << endl;

    string studentID, name, email, studentType, sectionID;
    float gpa;

    cin.ignore();
    cout << "Student ID: ";
    getline(cin, studentID);
    cout << "Name: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);
    cout << "Type (Regular/Scholarship/Exchange): ";
    getline(cin, studentType);
    cout << "GPA: ";
    cin >> gpa;
    cin.ignore();
    cout << "Section ID: ";
    getline(cin, sectionID);

    ifstream sections("sections.txt");
    string line;
    bool found = false;
    string venueID, timeSlot;

    while (getline(sections, line))
    {
        if (db.getField(line, 0) == sectionID)
        {
            venueID = db.getField(line, 3);
            timeSlot = db.getField(line, 4);
            found = true;
            break;
        }
    }
    sections.close();

    if (!found)
    {
        cout << "Section not found!" << endl;
        return;
    }

    int capacity = db.getVenueCap(venueID);
    int enrolled = db.countStudentsInSection(sectionID);

    if (enrolled >= capacity)
    {
        cout << "FAILED: Section is full!" << endl;
        return;
    }

    if (db.checkConflict(studentID, timeSlot))
    {
        cout << "FAILED: Time conflict!" << endl;
        return;
    }

    db.addRecord("Students.txt", studentID + "|" + name + "|" + studentType + "|" + to_string(gpa));
    db.addStudentToSection(studentID, sectionID);

    cout << "SUCCESS: Student registered!" << endl;
}

void teacherFeedback()
{
    cout << "\n=== TEACHER FEEDBACK ===" << endl;

    string teacherID;
    int rating;

    cout << "Teacher ID: ";
    cin >> teacherID;

    ifstream file("Teachers.txt");
    string line;
    bool found = false;
    string name, email;

    while (getline(file, line))
    {
        if (db.getField(line, 0) == teacherID)
        {
            name = db.getField(line, 1);
            email = db.getField(line, 2);
            found = true;
            break;
        }
    }
    file.close();

    if (!found)
    {
        cout << "Teacher not found!" << endl;
        return;
    }

    cout << "Teacher: " << name << endl;
    cout << "Rating (1-5): ";
    cin >> rating;

    if (rating >= 1 && rating <= 5)
    {
        Teacher teacher(teacherID, name, email);
        teacher.addRating(rating);
    }
    else
    {
        cout << "Invalid rating!" << endl;
    }
}

void gradingSystem()
{
    cout << "\n=== BIG RED BUTTON ===" << endl;

    string sectionID;
    cout << "Section ID: ";
    cin >> sectionID;

    db.inputMarks(sectionID);
    cout << "Grades updated in assessments.txt" << endl;
}

void runScheduler()
{
    Scheduler s;
    s.runAudit();
}

void polymorphismDemo()
{
    cout << "\n=== POLYMORPHISM DEMO ===" << endl;

    RegularStudent regular("R001", "Ali Raza", "ali@fast.edu", 3.2);
    ScholarshipStudent scholar("S001", "Sara Khan", "sara@fast.edu", 3.8);
    ExchangeStudent exchange("E001", "John Smith", "john@fast.edu", 0);

    regular.addCourse("CS101", 85);
    regular.addCourse("CS102", 72);
    regular.calculateGPA();

    scholar.addCourse("CS101", 78);
    scholar.addCourse("CS102", 68);
    scholar.calculateGPA();

    exchange.addCourse("CS101", 65);
    exchange.addCourse("CS102", 55);
    exchange.calculateGPA();

    Student *students[3] = {&regular, &scholar, &exchange};

    for (int i = 0; i < 3; i++)
    {
        students[i]->displayProfile();
        students[i]->viewTranscript();
        cout << "------------------------" << endl;
    }

    CoreCourse core("CS101", "Programming", "T001");
    ElectiveCourse elective("CS201", "Web Dev", "T002");
    LabCourse lab("CS301", "Networks Lab", "T001");

    cout << "\nCourse Exam Durations:" << endl;
    cout << "Core Course: " << core.getExamHours() << " hours" << endl;
    cout << "Elective Course: " << elective.getExamHours() << " hours" << endl;
    cout << "Lab Course: " << lab.getExamHours() << " hours" << endl;
}