#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, row, col, flag;
    char map[51][51];

    scanf("%d %d", &N, &M);
    getchar();

    row = 0;
    col = 0;

    for (int i = 0; i < N; i++) {
        gets(map[i]);
    }

    for (int i = 0; i < N; i++) {
        flag = 0;
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'X') {
                flag = 1;
                break;
            }
        }
        if (flag == 0) row++;
    }

    for (int i = 0; i < M; i++) {
        flag = 0;
        for (int j = 0; j < N; j++) {
            if (map[j][i] == 'X') {
                flag = 1;
                break;
            }
        }
        if (flag == 0) col++;
    }

    printf("%d\n", row > col ? row : col);
    return 0;
}