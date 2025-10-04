/**
 * main.cpp
 * linkedList demo code
 * CS 3100
 *
 * This project demos a simple linked list, implemented in the Student class, which
 * stores the student's grades as chars. This file contains test functions for adding grades,
 * checking for memory leaks, and testing copies
 */
#include "Student.h"
#include <iostream>

using namespace std;

void addSomeGrades(Student stud);

void testAddGrade();

void testCopy();

void testAssign();

void testForMemLeak();

void testForMemLeakCopy();

void testForMemLeakAssign();

void testBracketOp();

int main() {
    // uncomment which test you want to run

    // testAddGrade();

    // testForMemLeak();

    // testCopy();
    // testAssign();

    //testForMemLeakCopy();
    //testForMemLeakAssign();

    testBracketOp();

    return 0;
}

void testBracketOp() {
    Student s1;

    s1.addGrade('X');
    s1.addGrade('Y');
    s1.addGrade('Z');
    cout << s1 << endl << endl; // grades should be X, Y, Z

    s1[4] = 'A'; // call operator[], passing in 4, and place 'A' in the return reference
    cout << endl << s1 << endl; // grades should be A, Y, Z
    cout << endl;

    s1.operator[](4) = 'B'; // this is just the expanded syntax for s1[4] = 'B'
    cout << endl << s1 << endl; // grades should be B, Y, Z
}

// test if we can add grades to the Student's grade list
void testAddGrade() {
    Student addTest("Add", "Test", 2342);

    cout << "in testAddGrade():" << endl;
    cout << addTest << endl;
    cout << endl;

    addTest.addGrade('A');
    addTest.addGrade('F');
    addTest.addGrade('C');
    addTest.addGrade('A');
    addTest.addGrade('D');


    cout << "in testAddGrade():" << endl;
    cout << addTest << endl;
    cout << endl;
}

// test the Student copy constructor
void testCopy() {
    Student copyTest("Copy", "Test", 2342);

    copyTest.addGrade('A');
    copyTest.addGrade('F');

    cout << "in testCopy():" << endl;
    cout << copyTest << endl;
    cout << endl;

    addSomeGrades(copyTest);

    cout << "in testCopy():" << endl;
    cout << copyTest << endl;
    cout << endl;
}

// test the Student's assignment operator
void testAssign() {
    Student assignTest("Assign", "Test", 2342);

    assignTest.addGrade('A');
    assignTest.addGrade('F');

    Student anotherStud("Eloise", "Hawking", 4815);
    anotherStud.addGrade('D');
    anotherStud.addGrade('B');

    cout << "in testAssign(), before assignment:" << endl;
    cout << "Student assignTest:" << endl;
    cout << assignTest << endl;
    cout << "Student anotherStud:" << endl;
    cout << anotherStud << endl;
    cout << endl;


    anotherStud = assignTest;

    cout << "in testAssign(), after assignment:" << endl;
    cout << "Student assignTest:" << endl;
    cout << assignTest << endl;
    cout << "Student anotherStud:" << endl;
    cout << anotherStud << endl;
    cout << endl;

    assignTest.addGrade('X');
    assignTest.addGrade('Y');
    anotherStud.addGrade('U');
    anotherStud.addGrade('V');

    cout << "in testAssign(), after adding some more grades to both:" << endl;
    cout << "Student assignTest:" << endl;
    cout << assignTest << endl;
    cout << "Student anotherStud:" << endl;
    cout << anotherStud << endl;
    cout << endl;
}

// test the Student class for memory leaks
void testForMemLeak() {
    cout << "in testForMemLeak():" << endl;
    cout << "Before memory leak test loop..." << endl;
    cout << endl;

    for (int i = 0; i < 500000; i++) {
        Student memLeakTester("MemLeak", "Tester", i);
        memLeakTester.addGrade('A');
        memLeakTester.addGrade('F');
        memLeakTester.addGrade('B');
        memLeakTester.addGrade('D');
        memLeakTester.addGrade('C');
    }

    cout << "After memory leak test loop..." << endl;
    cout << endl;
}

// test if the copy constructor results in any memory leaks
void testForMemLeakCopy() {
    cout << "in testForMemLeakCopy()" << endl;
    cout << "Before memory leak test loop..." << endl;
    cout << endl;

    for (int i = 0; i < 100000; i++) {
        Student copyTest("Copy", "Test", 9999);

        copyTest.addGrade('M');
        copyTest.addGrade('E');
        copyTest.addGrade('M');

        addSomeGrades(copyTest);
    }
    cout << "After memory leak test loop..." << endl;
    cout << endl;
}

// test if the assignment operator results in any memory leaks
void testForMemLeakAssign() {
    cout << "in testForMemLeakAssign():" << endl;
    cout << "Before memory leak test loop..." << endl;
    cout << endl;

    for (int i = 0; i < 100000; i++) {
        Student assignTest("Assign", "Test", 2342);

        assignTest.addGrade('A');
        assignTest.addGrade('F');

        Student anotherStud("Eloise", "Hawking", 4815);
        anotherStud.addGrade('D');
        anotherStud.addGrade('B');

        //anotherStud = assignTest;

        assignTest.addGrade('X');
        assignTest.addGrade('Y');
        anotherStud.addGrade('U');
        anotherStud.addGrade('V');
    }
    cout << "After memory leak test loop..." << endl;
    cout << endl;
}

// helper function to add some grades to the Student that was passed in
// The student is passed by value, meaning all the member variables are
// copied from the original one to the local parameter
// If we implement the copy constructor, it will be used to do the copy
void addSomeGrades(Student stud) {
    stud.addGrade('C');
    stud.addGrade('A');
    stud.addGrade('D');
    stud.addGrade('B');

    // change other fields to check if they are copied
    stud.setFname("Eloise");
    stud.setLname("Hawking");
    stud.setUid(4815);

    cout << "in addSomeGrades(Student):" << endl;
    cout << stud << endl;
    cout << endl;
}
