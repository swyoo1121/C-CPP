#include <stdio.h>

int main() {
    int graph[101][101] = {0, };
    int x1, y1, x2, y2, result = 0;

    for (int i = 0; i < 4; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                graph[k][j] = 1;
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