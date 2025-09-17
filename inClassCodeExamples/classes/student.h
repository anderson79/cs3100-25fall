/*
 * CS 3100
 * In-class Code Examples
 * student.h
 *
 * This file contains the declaration of the student class.
 * The definition/implementation of methods appears in student.cpp
 */

#ifndef CLASSES_STUDENT_H
#define CLASSES_STUDENT_H
#include <string>
using namespace std;

// your code goes here
class Student {
public:
    string fname;
    string lname;
    size_t uid; // unsigned int

    // default constructor
    Student();

    // parameterized constructor
    Student(string fname, string lname, size_t uid);


};

#endif //CLASSES_STUDENT_H