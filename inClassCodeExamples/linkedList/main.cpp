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

int main() {
    testAddGrade();

    // testForMemLeak();

    // testCopy();
    // testAssign();

    //testForMemLeakCopy();
    //testForMemLeakAssign();

    return 0;
}

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


    //anotherStud = assignTest;


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
