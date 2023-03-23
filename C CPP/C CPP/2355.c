#include <stdio.h>

int main() {
    long long int A, B;

    scanf("%lld %lld", &A, &B);

    if (A > B) {
        long long int swap = A;
        A = B;
        B = swap;
    }

    printf("%lld\n", (A + B) * (B - A + 1) / 2);
    return 0;
}