/**
* @file BracketOp.cpp
* @brief definition of BracketOp, which serves as an example of overriding
* the bracket operator for a class
*
* @author james 
* @date  10/2/2025.
*/

#include "BracketOp.h"

BracketOp::BracketOp(): bracketParam(0)  {
    values = {"first", "second", "third"};
}

/**
 * This is the definition of overriding the bracket operator. We can use it like:
 *
 * BracketOp op;
 * string result = op[2];
 * result[1] = "update"
 *
 * If the values member array initially was
 *
 * ("first", "second", "third")
 * after those lines, result would have "third" and the values array would look like
 * ("first", "update", "third")
 *
 * If you pass operator[] an index larger than vector size - 1, an exception is thrown
 *
 * @param param when we have a BracketOp object, we can use bracketOp[number], which
 * calls this method and passes number into the function as param
 *
 * @return a reference to the string in the values array, because it is a reference we can
 * both retrieve the string and modify the original string stored in values
 */
string& BracketOp::operator[](size_t param) {
    cout << "-----------------------------" << endl;
    cout << "BracketOp::operator[](param=" << param << ")" << endl;
    cout << *this << endl;
    cout << "-----------------------------" << endl;

    bracketParam = param * 2;

    if (param >= values.size()) {
        throw exception();
    }
    return values[param];
}

/**
 * Stream insertion operator can be used to print the
 * object out like:
 *
 * cout << myBracketOp << endl;
 *
 * @param os ostream reference where the output will go
 * @param bracketOp the BracketOp object to output
 * @return the ostream that was passed in as os
 */
ostream& operator<<(ostream& os, const BracketOp& bracketOp) {
    os << "BracketOp{bracketParam=" <<  bracketOp.bracketParam
    << ", values=(";
    for (auto& val: bracketOp.values) {
        os << val << ", ";
    }
    os << "\b\b)}";


    return os;
}
