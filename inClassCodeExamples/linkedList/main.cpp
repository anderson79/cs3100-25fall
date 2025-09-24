#include "Student.h"
#include <iostream>

int main() {
    Student s("James", "Anderson", 2342);
    Student s1;

    s.addGrade('A');
    s.addGrade('F');

    std::cout << "Hello, World!" << std::endl;
    return 0;
}