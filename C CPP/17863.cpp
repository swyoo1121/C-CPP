#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    if (S.find("555") == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}