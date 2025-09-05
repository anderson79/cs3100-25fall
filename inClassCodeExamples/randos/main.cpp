/*
* CS 3100
* In class C++ examples
* 9/5/2025
* This file has demos for getting input from the console, seeding the random
* number generator and generating random numbers
*/
#include <iostream>

using namespace std;

int main() {
    // seed the random number generator with the current time in seconds
    srand(time(nullptr));

    int num = 0;
    cout << "Enter a number: ";
    // cin gets input from user and stores it in num
    cin >> num;

    cout << "You entered: " << num << endl;

    // print 20 random numbers
    for (int i = 0; i < 20; i++) {
        int rnd = (rand() % num) + 20;
        cout << "rnd " << rnd << endl;
    }

    return 0;
}
