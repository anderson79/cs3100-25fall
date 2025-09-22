/*
* CS 3100
 * In-class Code Examples
 * student.cpp
 *
 * This file contains the definition/implementation of the student class.
 */

#include "student.h" // the compiler needs to know everything about the member
// variables and functions for Student in order to use them
// so we include the class declaration here

#include <iostream>

using namespace std;

/**
 * Default constructor
 * For this constructor the member variables are initialized
 * inside the constructor body
 */
Student::Student() {
    fname = "NO";
    lname = "NAME";
    uid = -1;
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
      lname(lname) {
    setUid(uid);
}

string Student::getFname() const {
    // fname = "DIFFERENT NAME";   // since getFname is const, we cannot modify any member
    // variables inside this method

    // setUid("DIFFERENT NAME");  // we cannot call any methods not labeled as const either
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
        uid = newUid;
    } else {
        uid = -1;
    }
}

/**
 * this print student prints directly to cout
 */
void Student::printStudent() const {
    cout << getLname() << ", " << getFname() << " UID: " << getUid() << endl;
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

bool Student::operator==(const Student& other) const {
    return getUid() == other.getUid();
}

ostream& operator<<(ostream& os, const Student& student) {
    os << student.getLname() << ", " << student.getFname() << " UID: " << student.getUid() << endl;
    return os;
}