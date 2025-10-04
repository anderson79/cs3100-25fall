/**
* @file BracketOp.h
* @brief declaration of the BracketOp class, which stores a size_t bracketParam
* and a vector of string values, which are used to demonstrate how you can use
* the bracket operator
*
* @author james 
* @date  10/2/2025.
*/

#ifndef BRACKETOP_BRACKETOP_H
#define BRACKETOP_BRACKETOP_H

#include <iostream>
#include <vector>

using namespace std;

class BracketOp {
private:
    size_t bracketParam;
    vector<string> values;

public:
    BracketOp();

    string& operator[](size_t param);

    friend ostream& operator<<(ostream& os, const BracketOp& bracketOp);
};


#endif //BRACKETOP_BRACKETOP_H