#include <iostream>
#include <string>

using namespace std;

int main() {
    int word = 1;
    string S;

    getline(cin, S);

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ',') word++;
        else continue;
    }

    cout << word << endl;
    return 0;
}