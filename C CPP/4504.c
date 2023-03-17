#include <stdio.h>

int main() {
    int n, input;

    scanf("%d", &n);

    while (1) {
        scanf("%d", &input);
        if (input == 0) break;

        if (input % n == 0) printf("%d is a multiple of %d.\n", input, n);
        else printf("%d is NOT a multiple of %d.\n", input, n);
    }

    return 0;
}