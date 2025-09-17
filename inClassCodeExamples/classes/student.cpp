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

// Default constructor
// member variables initialized in constructor body
Student::Student() {
    fname = "INVALID";
    lname = "NAME";
    uid = -1;
}

// parameterized constructor
// member variables initialized in initializer list
Student::Student(string fname, string lname, size_t uid) : fname(fname), lname(lname), uid(uid){
}