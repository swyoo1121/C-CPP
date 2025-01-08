#include <stdio.h>

int main(void) {
    int N, K, result = 0;

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {
            K--;
        }

        if (K == 0) {
            result = i;
            break;
        }
    }

    printf("%d", result);
    return 0;
}