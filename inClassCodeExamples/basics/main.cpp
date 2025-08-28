/**
 * CS 3100
 * In class code examples
 * 8/27/2025
 * This file has examples for using cout, types like int, double, float, char, bool, and the const keyword
 * And it uses preprocessor directives such as #include and #define
 */
#include <iostream>
#include <string>

using namespace std;

// #define is a preprocessor directive, this happens before your code gets compiled, just like #include
// everywhere the preprocessor sees ARRAY_SIZE, it will replace it with 10
//
#define ARRAY_SIZE_MACRO 23

int main() {
    const int ARRAY_SIZE_CONST = 42; // because ARRAY_SIZE is const, I must initialize it when I declare it
    int i = ARRAY_SIZE_CONST;
    int j = ARRAY_SIZE_MACRO;

    cout << "Hello world! " << endl;
    cout << i << endl;
    cout << j << endl;
    cout << ARRAY_SIZE_CONST << endl;
    cout << ARRAY_SIZE_MACRO << endl;

    cout << "ARRAY_SIZE_MACRO" << endl; // if we

    // some other types we might see
    double dbl = 4.3;
    float flt = 4.3f;
    char ch = 'c';
    // there is a boolean type, but it is really just 0=false, 1=true
    bool flag = false;
    if (0) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << flag << endl;

    // strings are useful, there are many methods you can check out here
    // https://cppreference.com/w/cpp/string/basic_string.html
    string str = "James";
    str = str + " is cool";
    cout << str << endl;

    return 0;
}