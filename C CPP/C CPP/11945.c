#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    char bread[10][10];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", &bread[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = M - 1; j >= 0; j--) {
            printf("%c", bread[i][j]);
        }
        printf("\n");
    }

    return 0;
}