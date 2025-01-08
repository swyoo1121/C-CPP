#include <stdio.h>

int main() {
    int A, B, C;

    scanf("%d %d", &A, &B);
    scanf("%d", &C);

    printf("%d\n", A + B >= C * 2 ? A + B - C * 2 : A + B);
    return 0;
}