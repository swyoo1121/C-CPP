#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    int count = 0;
    double input;
    double result = 0;

    while (true) {
        cin >> S >> input;
        result += input;
        count++;

        if (S == "9390709") break;
    }

    cout << count << ' ' << result << endl;
    cout << result / count << endl;
}