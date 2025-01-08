#include <iostream>

using namespace std;

int main() {
    int result = 0, N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int target = i, divisor = 0;

        while (target > 0) {
            divisor += target % 10;
            target /= 10;
        }

        if (i % divisor == 0) result++;
    }

    cout << result << endl;
    return 0;
}