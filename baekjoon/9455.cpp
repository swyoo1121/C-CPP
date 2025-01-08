#include <iostream>

using namespace std;

int main(void) {
    int T, m, n, result;
    int box[101][101];

    cin >> T;

    for (int testcase = 0; testcase < T; testcase++) {
        cin >> m >> n;
        result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> box[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (box[j][i] == 0) continue;
                else {
                    for (int k = j; k < m; k++) {
                        if (box[k][i] == 0) result++;
                    }
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}