#include <stdio.h>

int main() {
    double before, after;

    before = 0;
    scanf("%lf", &after);

    while (after != 999) {
        before = after;
        scanf("%lf", &after);

        if (after == 999) break;

        printf("%.2lf\n", after - before);
    }
    return 0;
}