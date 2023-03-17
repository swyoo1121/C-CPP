#include <stdio.h>

int main(void) {
    int M, F;

    scanf("%d %d", &M, &F);

    while (M != 0 && F != 0) {
        printf("%d\n", M + F);
        scanf("%d %d", &M, &F);
    }

    return 0;
}