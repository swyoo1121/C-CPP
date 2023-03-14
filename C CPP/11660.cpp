#include <iostream>

using namespace std;

int N, M, input, x1, x2, y1, y2;
int sum[1025][1025] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> input;

            if (i == 1 && j == 1) sum[i][j] = input;
            else if (i == 1) sum[i][j] = sum[i][j - 1] + input;
            else if (j == 1) sum[i][j] = sum[i - 1][j] + input;
            else sum[i][j] = sum[i-1][j] + sum[i][j-1] + input - sum[i-1][j-1];
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}