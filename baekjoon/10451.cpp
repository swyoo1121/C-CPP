#include <iostream>

using namespace std;

int T, N, input, result;
int arr[1001][1001] = {0, };
int visited[1001] = {0, };

void dfs(int n) {
    visited[n] = 1;
    for (int i = 1; i <= N; i++) {
        if (arr[n][i] == 1) {
            if (!visited[i]) {
                dfs(i);
            }
            arr[n][i] = 0;
        }
    }
}

int main() {
    cin >> T;

    for (int test = 0; test < T; test++) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> input;
            visited[i] = 0;
            arr[i][input] = 1;
        }

        result = N;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs(i);
            else result--;
        }

        cout << result << endl;
    }
    return 0;
}