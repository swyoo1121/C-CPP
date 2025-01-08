#include <iostream>

using namespace std;

int main() {
    int n, flag, index = 1;

    while (true) {
        cin >> n;

        if (n == 0) break;

        n *= 3;

        if (n % 2 == 0) {
            n /= 2;
            flag = 0;
        }
        else {
            n = (n + 1) / 2;
            flag = 1;
        }

        n *= 3;

        n /= 9;

        if (flag == 0) cout << index << ". even " << n << endl;
        else cout << index << ". odd " << n << endl;

        index++;
    }
    return 0;
}