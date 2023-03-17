#include <iostream>

using namespace std;

int main() {
    int N, m, M, T, R;
    int minute = 0, X;

    cin >> N >> m >> M >> T >> R;
    X = m;

    while (N > 0) {
        minute++;

        if (M - m < T) break;

        if (X + T <= M) {
            X += T;
            N--;
        }
        else if (X - R < m) {
            X = m;
        }
        else {
            X -= R;
        }
    }

    if (N == 0) cout << minute << endl;
    else cout << -1 << endl;

    return 0;
}