#include <iostream>
#include <string>

using namespace std;

int main() {
    string S, number;
    int sum = 0;

    getline(cin, S);

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ',') {
            sum += stoi(number);
            number = "";
        }
        else number += S[i];
    }
    cout << sum + stoi(number) << endl;
    return 0;
}