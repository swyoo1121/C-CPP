#include <stdio.h>

int main(void) {
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);

    printf("%d", B - A - 1 > C - B - 1 ? B - A - 1 : C - B -1);
    return 0;
}