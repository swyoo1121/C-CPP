#include <iostream>

using namespace std;

int main() {
    int N, K, input;

    cin >> N >> K;

    while (K--) {
        cin >> input;
        N -= (input + 1) / 2;
    }

    if (N <= 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}