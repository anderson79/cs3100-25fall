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

void printStudent(const Student& s) {
    cout << s.getLname() << ", " << s.getFname() << " UID: " << s.getUid() << endl;
}

int main() {
    Student s1; // create a student object on the stack
    // after this line, s1 is a valid student

    // using setters to set student data
    s1.setFname("James");
    s1.setLname("Anderson");
    s1.setUid( 1000000000); // invalid UID by calling setUid

    // parameterized constructor will call setUid to check for valid UID
    Student s2("Eloise", "Hawking", 1000000000);

    s1.printStudent();
    s2.printStudent(cout); // we can pass other output streams
                            // and direct the output to other places

    return 0;
}
