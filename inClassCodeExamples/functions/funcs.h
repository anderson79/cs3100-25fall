//
// Created by drink on 9/15/2025.
//

#ifndef FUNCTIONS_FUNCS_H
#define FUNCTIONS_FUNCS_H

// your code goes here
#include <string>

// prototype / declarations

// pass by value (copy)
int squared(int value);

// another version of squared passing a double instead of int
double squared(double value);

// another version of squared where we pass a pointer to an int
void squared(int *ptr);

// int& means reference to an int
// pass by reference
void sqRef(int &ref);

void stringRef(std::string &ref);

void stringConstRef(const std::string &ref);

// your code stops here
#endif //FUNCTIONS_FUNCS_H