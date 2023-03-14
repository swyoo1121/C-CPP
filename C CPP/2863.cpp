#include <iostream>

using namespace std;

int main() {
    int result;
    double a, b, c, d, temp, update;
    cin >> a >> b >> c >> d;

    temp = a / c + b / d;
    result = 0;

    update = c / d + a / b;

    if (temp < update) {
        temp = update;
        result = 1;
    }

    update = d / b + c / a;

    if (temp < update) {
        temp = update;
        result = 2;
    }

    update = b / a + d / c;

    if (temp < update) {
        temp = update;
        result = 3;
    }

    cout << result << endl;

    return 0;
}