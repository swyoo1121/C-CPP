#include <stdio.h>

int main() {
    int N, B, before = 0, round = 1;
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &B);
        printf("%d ", B * round - before);
        before = B * round;
        round++;
    }

    printf("\n");
    return 0;
}