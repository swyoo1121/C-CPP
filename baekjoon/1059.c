#include <stdio.h>

int main() {
    int S[51], L, n, min, max;

    min = 0;
    max = 1000;

    scanf("%d", &L);

    for (int i = 0; i < L; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &n);

    for (int i = 0; i < L; i++) {
        if (S[i] < n) {
            if (n - S[i] < n - min) min = S[i];
        }
        else {
            if (S[i] - n < max - n) max = S[i];
        }
    }

    if (n == min || n == max) printf("0");
    else printf("%d", (n - min) * (max - n) - 1);

    return 0;
}