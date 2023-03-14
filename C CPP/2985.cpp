#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;

    cin >> A >> B >> C;

    if (A >= B && A >= C) {
        if (A == B + C) cout << A << '-' << B << '=' << C;
        else cout << A << '/' << B << '=' << C;
    }
    else if (B >= A && B >= C) {
        if (A == B - C) cout << A << '=' << B << '-' << C;
        else cout << A << '=' << B << '/' << C;
    }
    else if (C >= A && C >= B) {
        if (C == A + B) cout << A << '+' << B << '=' << C;
        else cout << A << '*' << B << '=' << C;
    }
}