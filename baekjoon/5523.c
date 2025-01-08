#include <stdio.h>

int main() {
    int N, A, B, winA, winB;

    winA = 0;
    winB = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);

        if (A > B) winA++;
        else if (A < B) winB++;
        else continue;
    }

    printf("%d %d\n", winA, winB);
    return 0;
}