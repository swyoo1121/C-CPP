#include <iostream>

using namespace std;

int penta(int n) {
    return n * n * n * n * n;
}

int main() {
    int n, result = 0;

    cin >> n;

    while (n) {
        int temp = n % 10;
        result += penta(temp);

        n /= 10;
    }

    cout << result << endl;
    return 0;

}