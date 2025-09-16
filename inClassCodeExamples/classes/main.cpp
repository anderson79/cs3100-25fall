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

int main() {
    Student s1; // create a student object on the stack
                // after this line, s1 is a valid student

    cout << "done\n";
    return 0;
}