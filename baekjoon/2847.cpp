#include <iostream>

using namespace std;

int score[101];
int N, result = 0;

int main() {
    cin >> N;

    for (int i = N - 1; i >= 0; i--) {
        cin >> score[i];
    }

    for (int i = 1; i < N; i++) {
        while(score[i-1] <= score[i]) {
            score[i]--;
            result++;
        }
    }

    cout << result << endl;
    return 0;
}