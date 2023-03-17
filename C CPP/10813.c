#include <stdio.h>

int main() {
    int N, M, i, j, basket[101];

    scanf("%d %d", &N, &M);

    for (int iter = 1; iter <= N; iter++) {
        basket[iter] = iter;
    } 

    for (int iter = 0; iter < M; iter++) {
        scanf("%d %d", &i, &j);
        int swap = basket[i];
        basket[i] = basket[j];
        basket[j] = swap;
    }

    for (int iter = 1; iter <= N; iter++) {
        printf("%d ", basket[iter]);
    }
    printf("\n");
    return 0;
}