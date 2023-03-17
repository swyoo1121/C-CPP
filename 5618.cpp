#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    if (n == 2) {
        int a, b;
        cin >> a >> b;

        int min = a;
        
        if (min > b) min = b;

        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0) {
                cout << i << endl;
            }
        }
    }
    else {
        int a, b, c;
        cin >> a >> b >> c;

        int min = a;
        
        if (min > b) min = b;
        if (min > c) min = c;

        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0 && c % i == 0) {
                cout << i << endl;
            }
        }
    }

    return 0;
}