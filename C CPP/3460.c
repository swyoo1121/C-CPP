#include <stdio.h>

int main() {
    int T, n, index;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        index = 0;

        while (n > 0) {
            if (n % 2) printf("%d ", index);
            index++;
            n /= 2;
        }
        printf("\n");
    }
    return 0;
}