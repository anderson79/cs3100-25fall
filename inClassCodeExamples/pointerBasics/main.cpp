/**
 * CS 3100
 * In-class C++ examples
 * 8/29/2025
 * pointer basics
 * This file contains some basic syntax for using pointers and working with addresses, as well as demonstrating
 * how arrays and pointers are ***nearly*** the same
 */
#include <iostream>

using namespace std;

int main() {
    int i = 7;

    cout << &i << endl; // get the address where i is in memory

    int *xyz = nullptr; // xyz is a pointer to an integer, nullptr sets it to 0
    xyz = &i; // get the address where i is in memory, and store it in xyz

    cout << "What is stored in xyz: " << xyz << endl;
    cout << "What is stored at the address xyz points to: " << *xyz << endl;
    cout << "What is stored at the address xyz + 1 points to: " << *(xyz - 1) << endl;
    // like arrays, C++ doesn't stop// you from accessing memory not
    // necessarily associated with
    // your program
    *xyz = 12; // dereference xyz, and place 12 in the memory address xyz points to
    cout << i << endl; // xyz points to i, so i should now be 12

    // pointers and arrays
    int arr[5];

    // these two lines do the exact same thing, just with different syntax
    // I would never use * to dereference an array like this in practice, this
    // is just a demonstration of how arrays act similary to pointers
    arr[0] = 15;
    *arr = 15;

    *(arr + 0) = 23; // arr[0] = 23
    *(arr + 3) = 42; // arr[3] = 42

    int *arrPtr = nullptr;
    //int j = *arrPtr; // if arrPtr is nullptr, using * to dereference it results in a segmentation fault
    if (arrPtr) {
        // null check, since C++ treats 0 as false and everything else as true, if arrPtr is nullptr
        // that is false, if arrPtr has a value (i.e. an address) this is true
        // if (arrPtr) is equivalent to if (arrPtr != nullptr)
        cout << *arrPtr << endl;
    } else {
        arrPtr = arr; // if arrPtr is nullptr, it is pointing to address x0, which we're not allowed to access
    }

    *arrPtr = 45; // since arrPtr now points to the first element in arr, this sets that element to 45
    *(arrPtr + 2) = 8; // same as arr[2] = 8
    arrPtr[1] = 16; // we can use arrPtr like an array, that might come in handy...

    return 0;
}
