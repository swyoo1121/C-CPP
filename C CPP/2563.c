#include <stdio.h>

int main() {
    int graph[101][101] = {0, };
    int T, x, y, result = 0;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &x, &y);
        for (int k = y; k < y + 10; k++) {
            for (int j = x; j < x + 10; j++) {
                graph[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (graph[i][j] == 1) result++;
        }
    }

    printf("%d\n", result);
    return 0;
}