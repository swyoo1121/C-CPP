#include <stdio.h>

int main(void) {
    int T, N, K, candy, sum;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &K);
        sum = 0;

        for (int j = 0; j < N; j++) {
            scanf("%d", &candy);
            sum += candy / K;
        }

        printf("%d\n", sum);
    }

    return 0;
}