/**
 * getline example
 * CS 3100
 * 9-22-2025
 *
 * This file has examples of how cin reads from the console into a string, and
 * how you can use getline to input an entire line of text to a string
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::vector<std::string> lines;
    std::string line;

    cin >> line; // when using cin to read a string, it reads up until the first whitespace
    cout << "line: " << line << endl;

    cin >> line; // if after the first cin, there are more characters, the next cin will continue to read until the next whitespace
    cout << "line: " << line << endl;

    getline(cin, line); // getline lets you get an entire line and put it in a string
    cout << "line: " << line << endl;

    return 0;
}
