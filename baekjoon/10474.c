#include <stdio.h>

int main() {
    int numerator, denominator;
    
    while (1) {
        scanf("%d %d", &numerator, &denominator);

        if (numerator == 0 && denominator == 0) break;

        printf("%d %d / %d\n", numerator / denominator, numerator % denominator, denominator);
    }

    return 0;
}