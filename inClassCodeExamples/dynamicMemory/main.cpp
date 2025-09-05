#include <iostream>

using namespace std;

int main() {
    int N = 0;
    cout << "Enter array size: ";
    cin >> N;

    char arr[N]; // C++ does not allow us to use a variable size for this kind of array

    char currChar = 'A';
    for (int i = 0; i < N; i++) {
        arr[i] = currChar++;
    }

    //arr = new int[50]; // cannot change what the static array is


}