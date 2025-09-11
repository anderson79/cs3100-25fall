/*
 * CS 3100
 * In-class C++ examples
 * 9/8/2025
 * dynamic memory allocation
 *
 * This file contains examples of how NOT to make a dynamic array on the stack. Then it shows the correct way
 * to use the 'new' keyword to allocate memory on the heap. In addition, because we use 'new' to allocate memory,
 * it is necessary to use 'delete' to release/free the memory back to the OS. Note that because we use 'new' to
 * allocate memory for an array of things, we need to use 'delete[]' when releasing memory. Also at the end a brief
 * example of using the C++ vector object, which is similar to ArrayList in Java that will automatically resize our array
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 0;
    cout << "Enter array size: ";
    cin >> N;

    //char arr[N]; // C++ does not allow us to create a variable sized array on the stack
                    // g++ uses an extension that can be disabled (see CMakeLists.txt)

    //arr = int[50]; // cannot change what the static array is

    char* dynArray = nullptr; // if we aren't initializing a pointer with an address it's good practice to
                                // initialize it to 'nullptr' so we don't accidentally try to access invalid memory

    // cout << *dynArray << endl;

    cout << "Before loop..." << endl; // to demonstrate memory leak (or lack of one) place a break point here and observe
                                        // how much memory your program is utilizing
    for (int i = 0; i < 10; i++) {
        dynArray = new char[N]; // the 'new' keyword asks the OS for memory on the heap to store the requested data
                                    // the return from using 'new' is the address to where that memory is
        char ch = 'A';
        for (int i = 0; i < N; i++) {
            dynArray[i] = ch;
            ch++;
        }

        delete[] dynArray; // tell the OS we are done with the memory we asked for when we used 'new'
                            // this does NOT affect what address is stored in dynArray, it still is pointing
                            // to the same place, only we have just released that memory
        dynArray = nullptr; // to be safe we want to set dynArray to nullptr to prevent us from
                            // trying to access invalid memory later

        if (dynArray != nullptr) { // we can also check if dynArray is not null with: if (dynArray)
            dynArray[3] = '7';
        }
        else {
            cout << "dynArray is nullptr" << endl;
        }
        //dynArray[1] = 'Q';  // even though we released the memory dynArray pointed to, C++ doesn't stop us
                            // from accessing/modifying it, similar to how we can access array elements out-of-bounds
    }
    cout << "After loop..." << endl; // place a breakpoint here to observe how much memory the program is utilizing
                                    // after many uses of 'new'. A small increase of 0.1 MB is normal, but several MB is not


    // in C++, the scope of a variable is the closest set of curly braces it is enclosed in
    {
        int test = 0;
    }
    // even though test isn't in a loop/if/function, it is only available in the scope of the curly braces and not here
    //cout << test;

    /////////////////////////////////////////////
    /// vector examples
    /// we need to #include <vector> at the beginning of the file

    vector<int> v; // declare an empty vector that can store ints

    // add 0, 1, 2... to back of vector
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    // we can use v[index] or v.at(index)
    cout << v.at(1) << endl;
    cout << v[1] << endl;

    // the difference is v[index] does not throw an exception for out of bounds
    // v.at(index) does throw an exception
    //cout << v[20] << endl;
    //cout << v.at(20);

    // many other methods:
    cout << v.front() << endl; // front() gets first element
    cout << v.back() << endl;  // back() gets last element
    v.pop_back();   // pop_back() removes last element
    cout << v.back() << endl;
    cout << v.data() << endl; // get the int pointer to the array
    cout << v.size() << endl; // get number of elements in array
    v.clear(); // resets vector to size of zero

    return 0;
}
