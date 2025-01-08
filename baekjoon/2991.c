#include <stdio.h>

int main() {
    int A, B, C, D;
    int P, M, N;
    int minute[1001] = {0, };
    
    scanf("%d %d %d %d", &A, &B, &C, &D);
    scanf("%d %d %d", &P, &M, &N);

    for (int i = 1; i < 1001; i++) {
        if ((i - 1) % (A + B) < A) minute[i]++;

        if ((i - 1) % (C + D) < C) minute[i]++;
    }

    printf("%d\n%d\n%d\n", minute[P], minute[M], minute[N]);
    return 0;

}