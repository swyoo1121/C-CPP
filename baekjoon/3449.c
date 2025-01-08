#include <stdio.h>

int main() {
    int T, dist;
    char a[101], b[101];

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%s", &a);
        scanf("%s", &b);
        dist = 0;

        for (int j = 0; a[j] != '\0'; j++) {
            if (a[j] != b[j]) dist++;
        }

        printf("Hamming distance is %d.\n", dist);
    }
    return 0;
}