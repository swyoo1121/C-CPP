#include <stdio.h>

int main() {
    int T;
    double A, B, C, D, E;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%lf %lf %lf %lf %lf", &A, &B, &C, &D, &E);
        printf("$%.2lf\n", 350.34 * A + 230.90 * B + 190.55 * C + 125.30 * D + 180.90 * E);
    }

    return 0;
}