/**
 * CS 3100
 * In class C++ examples
 * 8/27/2025
 * from https://en.cppreference.com/w/cpp/language/array.html
 *  A declaration of the form T a[N]; declares a as an array object that consists of N
 *  contiguously allocated objects of type T
 */
#include <iostream>

using namespace std;

int main() {
    int SIZE = 5;
    int arr[SIZE]; // we will discuss this, but SIZE ***MUST*** be a constant (or int literal)

    // before assigning indexes, the array will be full of garbage values
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (1 + i) * 100;
    }

    // I can make the loop go more times than SIZE
    // C++ doesn't stop me from accessing off the end of the array
    for (int i = 0; i < SIZE + 4; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
