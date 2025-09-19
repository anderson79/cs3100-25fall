/*
* CS 3100
 * In-class Code Examples
 * main.cpp
 *
 * This file contains all the tests we do with our student object.
 */
#include "student.h" // so main can know what a Student is, include the header

#include <iostream>

using namespace std;

void printStudent(Student s) {
    cout << s.lname << ", " << s.fname << " UID: " << s.uid << endl;
}

int main() {
    Student s1; // create a student object on the stack
    // after this line, s1 is a valid student

    s1.fname = "James";
    s1.lname = "Anderson";
    s1.uid = 481516;

    Student s2("Eloise", "Hawking", 2342108);

    printStudent(s1);
    printStudent(s2);

    return 0;
}
