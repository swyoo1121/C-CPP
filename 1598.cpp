#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B, dist = 0, diff = 0;

    cin >> A >> B;

    if (A > B) {
        int swap = A;
        A = B;
        B = swap;
    }

    diff = abs(B - A);

    A = (A - 1) % 4;
    B = (B - 1) % 4;

    if (A <= B) {
        dist = (diff / 4) + (diff % 4);
    }
    else {
        dist = (diff / 4) + (A - B) + 1;
    }

    cout << dist << endl;

}