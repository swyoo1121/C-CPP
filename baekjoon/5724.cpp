#include <iostream>

using namespace std;

int main() {
    int square[101] = {0, };
    int N;

    for (int i = 1; i <= 100; i++) {
        square[i] += i * i;
        square[i] += square[i - 1];
    }

    cin >> N;

    while (N != 0) {
        cout << square[N] << endl;
        cin >> N;
    }
    return 0;
}