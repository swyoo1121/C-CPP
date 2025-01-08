#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    char shape[101][101];

    scanf("%d", &N);
    getchar();

    for (int j = 1; j <= N; j++) {
        gets(shape[j]);
    }

    scanf("%d", &K);

    if (K == 1) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%c", shape[i][j]);
            }
            printf("\n");
        }
    }
    else if (K == 2) {
        for (int i = 1; i <= N; i++) {
            for (int j = N - 1; j >= 0; j--) {
                printf("%c", shape[i][j]);
            }
            printf("\n");
        }
    }
    else {
        for (int i = N; i >= 1; i--) {
            for (int j = 0; j < N; j++) {
                printf("%c", shape[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}