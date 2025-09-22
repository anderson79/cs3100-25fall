#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    std::vector<std::string> lines;
    std::string line;

    cin >> line;
    cout << "line: " << line << endl;

    cin >> line;
    cout << "line: " << line << endl;

    getline(cin, line);
    cout << "line: " << line << endl;

    return 0;
}
