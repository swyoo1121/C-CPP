#include <iostream>

using namespace std;

int t, n, x, far, close;

int main() {
    cin >> t;

    while (t--) {
        cin >> n;

        far = 0;
        close = 100;
        
        while (n--) {
            cin >> x;
            if (far < x) far = x;
            if (close > x) close = x;
        }

        cout << 2 * (far - close) << endl;
        }

    return 0;
}