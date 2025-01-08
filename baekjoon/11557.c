#include <stdio.h>
#include <string.h>

int main(void) {
    int T, N, L, max;
    char S[21], name[21];

    scanf("%d", &T);

    while (T > 0) {

        max = 0;
        strcpy(name, "");

        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%s %d", &S, &L);
            if (L > max) {
                max = L;
                strcpy(name, S);
            }
        }

        printf("%s\n", name);

        T--;
    }

    return 0;

}