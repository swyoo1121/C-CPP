#include <stdio.h>

int main(void) {
    int T, V, E;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &V, &E);
        printf("%d\n", 2 + E - V);
    }

    return 0;
}