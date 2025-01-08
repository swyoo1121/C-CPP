#include <stdio.h>

int visited[52][52];
int adj[52][52];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int M, N, K;


void reset() {
    for (int i = 0; i <= 52; i++) {
        for (int j = 0; j <= 52; j++) {
            visited[i][j] = 0;
            adj[i][j] = 0;
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (adj[nx][ny] == 1) {
                if (!visited[nx][ny]) {
                    dfs(nx, ny);
                }
            }
        }
        else continue;
    }

}   

int main() {
    int T, X, Y, result;

    scanf("%d", &T);

    for (int testcase = 0; testcase < T; testcase++) {
        scanf("%d %d %d", &M, &N, &K);
        result = 0;

        for (int input = 0; input < K; input++) {
            scanf("%d %d", &X, &Y);
            adj[Y][X] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (adj[i][j] == 1) {
                    if (!visited[i][j]) {
                        result++;
                        dfs(i, j);
                    }
                }
            }
        }
        printf("%d\n", result);
        reset();
    }

    return 0;
}