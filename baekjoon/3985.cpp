#include <iostream>

using namespace std;

int main() {
    int cake[1001] = {0, };
    int count[1001] = {0, };
    int L, N, P, K, max = 0, max_index, result = 0, result_index = 0;

    cin >> L;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P >> K;
        int length = K - P;

        if (max < length) {
            max = length;
            max_index = i;
        }

        for (int j = P; j <= K; j++) {
            if (cake[j] == 0) cake[j] = i;
        }
    }

    for (int i = 1; i <= L; i++) {
        count[cake[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (result < count[i]) {
            result = count[i];
            result_index = i;
        }
    }

    cout << max_index << endl << result_index << endl;
    return 0;
}