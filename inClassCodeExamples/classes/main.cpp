/*
* CS 3100
 * In-class Code Examples
 * main.cpp
 *
 * This file contains all the tests we do with our student object.
 */
#include <fstream>

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
    s1.setUid( 1234); // invalid UID by calling setUid

    // parameterized constructor will call setUid to check for valid UID
    Student s2("Eloise", "Hawking", 9876);

    s1.printStudent();
    s2.printStudent(cout); // we can pass other output streams
                            // and direct the output to other places


    //s1.operator==(s2); // this is what is actually hapening for s1 == s2
    if (s1 == s2) { // how to see if two student objects are the same?
        cout << "same";
    } else {
        cout << "different";
    }
    cout << endl;

    Student s3("Rocky", "Racoon", 1234);
    if (s1 == s3) { // how to see if two student objects are the same?
        cout << "same";
    } else {
        cout << "different";
    }
    cout << endl;


    //cout.operator<<(23); // here operator<< is a method of cout
    //operator<<(cout, 23); // not a method, just a function
    //cout.operator<<(23).operator<<( endl); // if operator<< returns an ostream&, we can chain calls together
    cout << s1 << endl; // using the friend function, chain together calls to operator<<

    // we can use << now to output Student to file too
    ofstream myFile("out.txt");
    myFile << s1 << endl;
    myFile.close();

    return 0;
}
