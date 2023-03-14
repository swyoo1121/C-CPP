#include <stdio.h>

int main() {
    int N, M, K, max = 0;

    scanf("%d %d %d", &N, &M, &K);

    N -= K;

    for (int i = 0; i <= K; i++) {
        int result = N / 2 < M ? N / 2 : M;
        if (max < result) max = result;

        N++;
        M--;
    }

    printf("%d\n", max);
    return 0;
}