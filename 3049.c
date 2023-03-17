#include <stdio.h>

int main() {
    int N;
    
    scanf("%d", &N);

    N *= (N - 1) * (N - 2) * (N- 3);

    if (N == 0) printf("0\n");
    else printf("%d\n", N / 24);

    return 0;
}