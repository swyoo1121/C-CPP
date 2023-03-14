#include <stdio.h>

long long int sum = 0;

int main(void) {
    int C, K, P;

    scanf("%d %d %d", &C, &K, &P);

    for (int i = 1; i <= C; i++) {
        sum += K*i;
        sum += P*i*i;
    }

    printf("%lld", sum);
}