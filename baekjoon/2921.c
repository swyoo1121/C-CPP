#include <stdio.h>

int N;
long long int domino = 0;

int main(void) {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        domino += i * i + i;
        for (int j = 1; j <= i; j++) {
            domino += j;
        }
    }

    printf("%lld", domino);
    return 0;
}