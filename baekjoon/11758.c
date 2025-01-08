#include <stdio.h>

int main(void) {
    int x1, y1, x2, y2, x3, y3, S;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    S = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;

    if (S > 0) {
        printf("1");
    } else if (S < 0) {
        printf("-1");
    } else {
        printf("0");
    }

    return 0;

}