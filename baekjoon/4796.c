#include <stdio.h>

int main(void) {
    int L, P, V, count;

    count = 1;

    scanf("%d %d %d", &L, &P, &V);

    while (L != 0 && P != 0 && V != 0) {
        printf("Case %d: %d\n", count, V / P * L + (V  % P < L ? V % P : L));
        count++;
        scanf("%d %d %d", &L, &P, &V);
    }

    return 0;

}