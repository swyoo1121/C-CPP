#include <stdio.h>

int adj[1001][1001];
int visited[1001] = {0, };
int discovered[1001] = {0, };

typedef struct Queue {
    int front, rear;
    int data[1001];
} Queue;

void dfs(int from, int N) {
    int to;

    visited[from] = 1;
    printf("%d ", from);

    for (int i = 1; i <= N; i++) {
        if(adj[from][i]) {
            to = i;
            if (!visited[to]) {
                dfs(to, N);
            }
        }
    }
}

void bfs(int start, int N) {
    int from, to;

    Queue q;
    q.front = -1;
    q.rear = -1;

    discovered[start] = 1;
    q.data[++q.rear] = start;

    while(q.front < q.rear) {
        from = q.data[++q.front];
        printf("%d ", from);

        for (int i = 1; i <= N; i++) {
            if (adj[from][i]) {
                to = i;

                if (!discovered[to]) {
                    discovered[to] = 1;
                    q.data[++q.rear] = to;
                }
            }
        }
    }
}

int main() {
    int N, M, V;
    int x, y;

    scanf("%d %d %d", &N, &M, &V);

    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &x, &y);

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    dfs(V, N);
    printf("\n");
    bfs(V, N);
    return 0;
}