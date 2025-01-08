#include <iostream>

using namespace std;

int main() {
    int a_three, a_two, a_one, b_three, b_two, b_one;

    cin >> a_three >> a_two >> a_one >> b_three >> b_two >> b_one;

    int a = a_three * 3 + a_two * 2 + a_one;
    int b = b_three * 3 + b_two * 2 + b_one;

    if (a > b) cout << 'A' << endl;
    else if (a < b) cout << 'B' << endl;
    else cout << 'T' << endl;

    return 0;
}