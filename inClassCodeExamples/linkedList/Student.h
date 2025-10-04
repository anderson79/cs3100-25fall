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
// your code goes here
#include "GradeNode.h"

#include <string>
using namespace std;

class Student {
public:
    string fname;
    string lname;
    size_t uid; // size_t == unsigned long long
    GradeNode *gradeListHead;

    void clearList();

public:
    // default constructor
    Student();

    // parameterized constructor
    Student(string fname, string lname, size_t uid);

    // TODO comment this
    // copy constructor - can make deep copy
    Student(const Student& other);
    // assignment operator
    Student& operator=(const Student& other);
    // destructor / deconstructor
    ~Student();

    // getters
    // the const qualifier after the method name means
    // the method cannot modify any of the member variables
    // of the class
    // in addition, const methods can only call other
    // methods that are labeled const, since those are
    // the only ones guaranteed not to modify the object
    string getFname() const;

    string getLname() const;

    size_t getUid() const;

    // setters
    void setFname(string newFname);

    void setLname(string newLname);

    void setUid(size_t newUid);

    // list methods
    void addGrade(char newGrade);

    // methods to print/output the student as a string
    void printStudent() const;

    void printStudent(ostream &os) const;

    void printGrades() const;

    void printGrades(ostream &os) const;

    // equality operator
    bool operator==(const Student &other) const;

    // string insertion operator
    friend ostream &operator<<(ostream &os, const Student &student);

    // demo of using operator[]
    // when you use this, it looks like
    // student[index];
    // this method gets called, and the index is passed in as position
    // we return a reference to a char, which means if we do
    // student[index] = 'A';
    // since that is a reference, it will put 'A' into the variable we return
    // from this method
    char& operator[](size_t position);

    // constant used to verify UID is being set to a valid
    // uid with a maximum of 8 digits
    const size_t MAX_UID = 99999999;
};

//ostream &operator<<(ostream &os, const Student &student);
//bool operator==(const Student& s1, const Student& s2);
#endif //CLASSES_STUDENT_H
