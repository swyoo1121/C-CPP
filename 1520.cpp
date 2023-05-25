#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, result = 0;
int maps[501][501];
int dp[501][501];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int dfs(int x, int y)
{
    if (x == N - 1 && y == M - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
 
    dp[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M)
        {
            if (maps[nx][ny] < maps[x][y])
            {
                dp[x][y] = dp[x][y] + dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maps[i][j];
            dp[i][j] = -1;
        }
    }

    result = dfs(0,0);

    cout << result << endl;
    return 0;

}