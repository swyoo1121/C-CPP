#include <iostream>

using namespace std;

long long int a, b, n;

long long int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
    cin >> n;

    while (n--) {
        cin >> a >> b;
        cout << a * b / GCD(a, b) << '\n';
    }

    return 0;
}