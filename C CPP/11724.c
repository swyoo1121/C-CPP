#include <stdio.h>

int adj[1001][1001];
int visited[1001];

void dfs(int from, int N) {
    int to;

    visited[from] = 1;

    for (int i = 1; i <= N; i++) {
        if (adj[from][i]) {
            to = i;
            if (!visited[to]) {
                dfs (to, N);
            }
        }
    }
}

int main() {
    int N, M, u, v, result = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, N);
            result++;
        }
    }
    
    printf("%d\n", result);
    return 0;
}