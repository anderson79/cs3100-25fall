/**
 * CS 3100
 * In-class code examples
 * C++ Functions
 *
 * This source file contains examples of creating and using functions, including passing by value (copy) and passing by reference
 */

#include "funcs.h"

#include <iostream>

using namespace std;

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

    string myString = "Hello World!";
    stringConstRef(myString);
    cout << "myString: " << myString << endl;
}
