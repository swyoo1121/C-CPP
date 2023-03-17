#include <iostream>

using namespace std;

int main() {
    int N, result = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int target = i;

        while (target > 0) {
            if (target % 10 != 0 && (target % 10) % 3 == 0) result++;
            target /= 10;
        }
    }

    cout << result << endl;
    return 0;
}