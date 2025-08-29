/**
 * CS 3100
 * In-class C++ examples
 * 8/29/2025
 * pointer basics
 * This file contains some basic syntax for using pointers and working with addresses
 */
#include <iostream>

using namespace std;

int main() {
    int i = 7;

    cout << &i << endl; // get the address where i is in memory

    int* xyz = nullptr; // xyz is a pointer to an integer, nullptr sets it to 0
    xyz = &i;   // get the address where i is in memory, and store it in xyz

    cout << "What is stored in xyz: " << xyz << endl;
    cout << "What is stored at the address xyz points to: " << *(xyz) << endl;
    cout << "What is stored at the address xyz + 1 points to: " << *(xyz + 1) << endl; // like arrays, C++ doesn't stop
                                                                                        // you from accessing memory not
                                                                                        // necessarily associated with
                                                                                        // your program

    return 0;
}
