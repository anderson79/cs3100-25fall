/**
 * bracketOp
 * CS 3100
 *
 * This project contains an example of overriding the bracket operator
 */
#include <iostream>

#include "BracketOp.h"


int main() {
    BracketOp bracketOp;

    size_t bracketOpParam = 2;
    string bracketOpString = "put me in the bracketOp!";

    cout << "before bracketOp[" << bracketOpParam << "]" << endl;
    // pass 2 into bracketOp, we can store the return in a string
    string returnVal = bracketOp[bracketOpParam];
    cout << "after bracketOp[" << bracketOpParam << "]" << endl;
    cout << bracketOp << endl;
    cout << "returnVal=" << returnVal << endl;

    bracketOpParam = 1;
    cout << endl << "before bracketOp[" << bracketOpParam << "] = \"" << bracketOpString << "\"" << endl;
    // pass 1 into bracketOp, which will return a reference to a string,
    // which we can assign to a different string, modifying the original
    bracketOp[bracketOpParam] = bracketOpString;
    cout << "after bracketOp[" << bracketOpParam << "] = \"" << bracketOpString << "\"" << endl;
    cout << bracketOp << endl;

    bracketOpParam = 0;
    cout << endl << "before bracketOp[" << bracketOpParam << "]" << endl;
    returnVal = bracketOp[bracketOpParam];
    cout << "after bracketOp[" << bracketOpParam << "]" << endl;
    cout << bracketOp << endl;
    cout << "returnVal=" << returnVal << endl;

    bracketOpParam = 6;
    cout << endl << "before bracketOp[" << bracketOpParam << "]" << endl;
    bracketOp[bracketOpParam];
    cout << "after bracketOp[" << bracketOpParam << "]" << endl;
    return 0;
}
