#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    while (1) {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;

        if (a > b) {
            int swap = a;
            a = b;
            b = swap;
        }
        if (a > c) {
            int swap = a;
            a = c;
            c = swap;
        }
        if (b > c) {
            int swap = b;
            b = c;
            c = swap;
        }

        if (a == b && b == c) cout << "Equilateral" << endl;
        else if (c >= a + b) cout << "Invalid" << endl;
        else if (a != b && b != c && c != a) cout << "Scalene" << endl;
        else cout << "Isosceles" << endl;

    }

    return 0;
}