#include <stdio.h>

int main() {
    int T, d, iter;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &d);
        iter = 0;

        do {
            if (d < iter * iter + iter) break;
            iter++;
        } while (1);

        printf("%d\n", iter - 1);        
    }

    return 0;
}