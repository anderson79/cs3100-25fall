//
// Created by drink on 9/15/2025.
//

#include <iostream>
#include <string>

using namespace std;

// below are the functions definitions of those declared above
void stringRef(string &ref) {
    ref.append(" Goodbye!");
}

void stringConstRef(const string &ref) {
    string refCopy = ref;
    refCopy = "Goodbye!";
}

// since ref is passed by reference, when we assign it a new value in sqRef, the variable passed in
// has it's value changed too
void sqRef(int &ref) {
    cout << "squared(int&)" << endl;

    int result = ref;
    cout << "result: " << result << endl;
    result *= result;
    cout << "result: " << result << endl;
    ref = result;
    cout << "ref: " << ref << endl;

    cout << endl;
}

//
void squared(int *ptr) {
    cout << "squared(int*)" << endl;

    if (ptr != nullptr) {
        int result = *ptr;
        cout << "result: " << result << endl;
        result *= result;
        *ptr = result;
        cout << "*ptr" << endl;
    }
    int i;
    ptr = &i;

    cout << endl;

    // this is the original squared(int*) from class, I simplified it above
    // int value = 0;
    // if (ptr != nullptr) {
    //     value = *ptr;
    // }
    // int result = squared(value);
    // cout << "result: " << result << endl;
    //
    // if (ptr != nullptr) {
    //     *ptr = result;
    //     cout << *ptr << endl;
    // }
}

int squared(int value) {
    cout << "squared(int)" << endl;
    int result = value * value;
    cout << "result: " << result << endl;
    cout << endl;

    return result;
}

double squared(double value) {
    cout << "squared(double)" << endl;
    cout << endl;

    return value * value;
}
