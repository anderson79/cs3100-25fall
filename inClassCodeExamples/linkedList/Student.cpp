/*
* CS 3100
 * In-class Code Examples
 * student.cpp
 *
 * This file contains the definition/implementation of the student class.
 */

#include "Student.h" // the compiler needs to know everything about the member
// variables and functions for Student in order to use them
// so we include the class declaration here

#include <iostream>

using namespace std;

/**
 * Default constructor
 * For this constructor the member variables are initialized
 * inside the constructor body
 *
 * UPDATE: this constructor now delegates construction to the parameterized constructor
 * the advantage of that is the other constructor handles setting gradeListHead to nullptr
 * so we don't have to do it here
 */
Student::Student() : Student("INVALID", "NAME", -1) {
    // fname = "NO";
    // lname = "NAME";
    // uid = -1;
    // gradeListHead = nullptr;
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
      lname(lname),
      gradeListHead(nullptr) {
    setUid(uid);
}

/**
 * copy constructor
 * The copy constructor copies all the fields of the other Student into this student
 * except for other.gradeListHead. Instead, a deep-copy of the other's grade list
 * is made for this student
 * @param other the Student copying from
 */
Student::Student(const Student& other) : Student(other.getFname(), other.getLname(), other.getUid()) {
    // get a copy of other's head pointer
    GradeNode* current = other.gradeListHead;

    // walk along the other's list, adding in each grade to this Student's list
    while (current) {
        addGrade(current->grade);
        current = current->next;
    }
}

/**
 * operator=
 * The assignment operator frees any memory that this Student may be referencing
 * in the grade list, copies all the fields from the other Student, then makes
 * a deep copy of the other Student's grade list
 * @param other The student to copy from
 * @return Reference to the Student that we copied into
 */
Student& Student::operator=(const Student& other) {
//  copy the value members from other into this one
    setFname(other.getFname());
    setLname(other.getLname());
    setUid(other.getUid());

    // this student may have grades in it's list, because this is not a brand new student
    // we need to clear this student's list before copying grades from the other's list
    clearList(); // luckily we wrote a method to do that for us!

    // this is a copy/paste from the copy constructor
    // get a copy of other's head pointer
    GradeNode* current = other.gradeListHead;

    // walk along the other's list, adding in each grade to this Student's list
    while (current) {
        addGrade(current->grade);
        current = current->next;
    }

    // we need to return a reference to this student
    // because references are values, we need to dereference
    // the 'this' pointer to get the object by value
    return *this;
}

/**
 * destructor
 * The destructor will be automatically called anytime a Student goes out of scope,
 * such as at the end of a function, or anytime the Student object is in the stack frame
 * that is being popped. The destructor is also called when delete is used on a pointer
 * to a Student
 */
Student::~Student() {
// just call clear list, it does all the work
    clearList();
}

/**
 * clearList walks along the grade list and releases the memory allocated for each node.
 * At the end of clearList, gradeListHead is nullptr, so the list is empty and new
 * grades can be inserted
 */
void Student::clearList() {
    //
    GradeNode* current = gradeListHead;

    while (current != nullptr) {
        GradeNode* nextToDie = current->next; // after we delete current, we cannot access current->next
                                            // so before that, we grab current->next, so we can update
                                            // current to point to the next node after deleting the current one
        delete current; // does NOT set current to nullptr
        current = nextToDie;
    }

    // now that all the memory from the nodes has been released, it's good to set the head to nullptr
    // this also makes the list truly clear, since when head is nullptr that means the list is empty
    gradeListHead = nullptr;
}

/**
 * getter for the fname member variable
 * @return the studen'ts first name
 */
string Student::getFname() const {
    // fname = "DIFFERENT NAME";   // since getFname is const, we cannot modify any member
    // variables inside this method

    // setUid(987654);  // we cannot call any methods not labeled as const either
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
        // keep user from assignning an invalid UID
        uid = newUid;
    } else {
        uid = -1; // if user tries an invalid UID, set it to -1 so we know
    }
}

/**
 * addGrade
 * add the new grade to the end of the node
 * @param newGrade
 */
void Student::addGrade(char newGrade) {
    GradeNode *newNodePtr;
    newNodePtr = new GradeNode; // allocate memory for the new node

    newNodePtr->grade = newGrade; // put the grade in the new node
    //(*newNodePtr).grade = newGrade; // does the same thing as above, just more complicated syntax

    newNodePtr->next = nullptr; // clear next pointer so not pointing to garbage

    // when head is null, the list is emtpy, so make head point to first node
    if (this->gradeListHead == nullptr) {
        // !gradeListHead
        this->gradeListHead = newNodePtr;
    } else {
        // get a temp pointer to head
        // we know the head is not null, otherwise we would have been in the other branch of the if statement
        GradeNode *current = gradeListHead;

        // walk along the list until current points to the last node in the list
        while (current->next != nullptr) {
            current = current->next;
        }

        // after while loop, current points to the last node
        // we want the last node's next to point to the new node we're adding
        current->next = newNodePtr;
    }
}

/**
 * this printStudent prints directly to cout
 */
void Student::printStudent() const {
    printStudent(cout);
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

/**
 * printGrades
 * this printGrades just prints the grades list to cout
 */
void Student::printGrades() const {
    printGrades(cout);
}

/**
 * this gradesList will output to the given ostream
 * @param os the ostream where the grades are output to
 */
void Student::printGrades(ostream &os) const {
    GradeNode* current = gradeListHead;

    os << "(";

    while (current != nullptr) {
        os << current->grade;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }

    os << ")";
}

/**
 * operator==
 * The equality operator determines of the other Student is the same as
 * this student by checking if the UID of each Student matches
 * @param other the Student we're checking is equal to this one
 * @return true if the Student's UIDs match, false otherwise
 */
bool Student::operator==(const Student &other) const {
    return getUid() == other.getUid();
}

/**
 * operator<<
 * The stream insertion operator outputs the Student as a string
 * to the given ostream
 * @param os the ostream where the Student is output to
 * @param student the Student being output
 * @return the ostream that was passed in
 */
ostream &operator<<(ostream &os, const Student &student) {
    student.printStudent(os);
    student.printGrades(os);

    return os;
}
