/**
 * CS 3100
 * In-class code examples
 * C++ Functions
 *
 * This source file contains examples of creating and using functions, including passing by value (copy) and passing by reference
 */

#include <iostream>

using namespace std;

// prototype / declarations
int squared(int value);

// another version of squared passing a double instead of int
double squared(double value);

// another version of squared where we pass a pointer to an int
void squared(int *ptr);

// int& means reference to an int
void sqRef(int &ref);

int main() {
    int num = 4;
    int *numPtr = &num;
    double numSquared;

    cout << "num: " << num << endl;
    cout << endl;

    squared(&num); // we can pass numPtr, or &num, which are both the address of num

    cout << "num: " << num << endl;
    cout << endl;

    sqRef(num); // when passing by reference, you don't get the address, just pass like normal

    cout << "num: " << num << endl;
    //cout << "numSquared: " << numSquared << endl;
}

// below are the functions definitions of those declared above


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
