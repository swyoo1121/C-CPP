#include <stdio.h>

int main() {
    int T, c, v;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &c, &v);

        printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c % v);
    }
    return 0;
}