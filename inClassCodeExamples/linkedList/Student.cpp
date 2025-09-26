/*
* CS 3100
 * In-class Code Examples
 * student.cpp
 *
 * This file contains the definition/implementation of the student class.
 */

#include "Student.h" // the compiler needs to know everything about the member
// variables and functions for Student in order to use them
// so we include the class declaration here

#include <iostream>

using namespace std;

/**
 * Default constructor
 * For this constructor the member variables are initialized
 * inside the constructor body
 */
Student::Student() : Student("INVALID", "NAME", -1) {
    // fname = "NO";
    // lname = "NAME";
    // uid = -1;
    // gradeListHead = nullptr;
}

/**
 * Paramaterized constructor
 * This constructor takes the student's first and last name, and
 * their UID to initialize the member variables.
 * This constructor uses the initializer list to initialize
 * lname and fname. In the constructor body, setUid(uid) is
 * used to do error checking on the UID
 * @param fname student's first name
 * @param lname student's last name
 * @param uid student's UID
 */
Student::Student(string fname, string lname, size_t uid)
    : fname(fname),
      lname(lname),
      gradeListHead(nullptr) {
    setUid(uid);
}

// Student::Student(const Student& other) : Student(other.getFname(), other.getLname(), other.getUid()) {
// TODO
// }

// Student& Student::operator=(const Student& other) {
// TODO
// }

// Student::~Student() {
// TODO
// }

void Student::clearList() {
    // TODO
}

string Student::getFname() const {
    // fname = "DIFFERENT NAME";   // since getFname is const, we cannot modify any member
    // variables inside this method

    // setUid(987654);  // we cannot call any methods not labeled as const either
    return fname;
}

/**
 * getter for the lname member variable
 * @return the student's last name
 */
string Student::getLname() const {
    return lname;
}

/**
 * getter for the uid member variable
 * @return student's uid
 */
size_t Student::getUid() const {
    return uid;
}

/**
 * Change the student's first name
 * @param newFname the new first name
 */
void Student::setFname(string newFname) {
    fname = newFname;
}

/**
 * Change the student's last name
 * @param newLname the new last name
 */
void Student::setLname(string newLname) {
    lname = newLname;
}

/**
 * If newUid is less than or equal to the max UID, uid will
 * be set to the new id. Otherwise, newUid is set to -1 indicating
 * an invalid UID
 * @param newUid the new uid
 */
void Student::setUid(size_t newUid) {
    if (newUid <= MAX_UID) {
        // keep user from assignning an invalid UID
        uid = newUid;
    } else {
        uid = -1; // if user tries an invalid UID, set it to -1 so we know
    }
}

/**
 * addGrade
 * add the new grade to the end of the node
 * @param newGrade
 */
void Student::addGrade(char newGrade) {
    GradeNode *newNodePtr;
    newNodePtr = new GradeNode; // allocate memory for the new node

    newNodePtr->grade = newGrade; // put the grade in the new node
    //(*newNodePtr).grade = newGrade; // does the same thing as above, just more complicated syntax

    newNodePtr->next = nullptr; // clear next pointer so not pointing to garbage

    // when head is null, the list is emtpy, so make head point to first node
    if (gradeListHead == nullptr) {
        // !gradeListHead
        gradeListHead = newNodePtr;
    } else {
        // get a temp pointer to head
        GradeNode *current = gradeListHead;
        //current->next != nullptr
    }
}

// a complete version of addGrade(char)
// void Student::addGrade(char newGrade) {
//     GradeNode* newNodePtr;
//     newNodePtr = new GradeNode; // allocate memory for the new node
//
//     newNodePtr->grade = newGrade; // put the grade in the new node
//     //(*newNodePtr).grade = newGrade; // does the same thing as above, just more complicated syntax
//
//     newNodePtr->next = nullptr; // clear next pointer so not pointing to garbage
//
//     // when head is null, the list is emtpy, so make head point to first node
//     if (gradeListHead == nullptr) { // !gradeListHead
//         gradeListHead = newNodePtr;
//     } else {
//         // get a temp pointer to head
//         GradeNode* current = gradeListHead;
//         while (current->next != nullptr) {
//             current = current->next;
//         }
//         current->next = newNodePtr;
//     }
// }

/**
 * this print student prints directly to cout
 */
void Student::printStudent() const {
    //cout << getLname() << ", " << getFname() << " UID: " << getUid() << endl;
    printStudent(cout);
}

/**
* this print student outputs to the given ostream
* that means we can output to any ostream, for example
* a file stream, a string stream, a network stream, etc.
 * @param os the output stream to output the student information to
 * as a string format
 */
void Student::printStudent(ostream &os) const {
    os << getLname() << ", " << getFname() << " UID: " << getUid() << endl;
}

void Student::printGrades() const {
    printGrades(cout);
}

void Student::printGrades(ostream &os) const {
    // TODO
}

bool Student::operator==(const Student &other) const {
    return getUid() == other.getUid();
}

ostream &operator<<(ostream &os, const Student &student) {
    student.printStudent(os);
    student.printGrades(os);

    return os;
}
