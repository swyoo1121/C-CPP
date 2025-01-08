#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int T, input, result;
    int score[5];

    cin >> T;

    while (T > 0) {
        T--;
        for (int i = 0; i < 5; i++) {
            cin >> input;
            score[i] = input;
        }

        sort(score, score + 5, compare);

        int result = score[1] + score[2] + score[3];

        if (score[3] - score[1] >= 4) cout << "KIN" << endl;
        else cout << result << endl;
    }

    return 0;
}