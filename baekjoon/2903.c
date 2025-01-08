#include <stdio.h>

int main() {
    int N, count = 2;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        count *= 2;
        count--;
    }

    printf("%d\n", count * count);
    return 0;
}