#include <stdio.h>

int main(void) {
    int n, a, b, cy, sd;
    cy = 100;
    sd = 100;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) sd -= a;
        else if (a < b) cy -= b;
        else continue;
    }

    printf("%d\n%d", cy, sd);
    return 0;
}