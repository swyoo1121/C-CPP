#include <iostream>

using namespace std;

int main() {
    int N, result = 0;

    cin >> N;

    for (int i = 1; i * i <= N; i++) {
        result++;
    }

    cout << result << endl;
    return 0;

}