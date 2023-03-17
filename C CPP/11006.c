#include <stdio.h>

int main(void) {
    int test, N, M, U, T;

    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        U = 0;
        T = 0;
        scanf("%d %d", &N, &M);

        while (1) {
            N -= 2;
            T++;
            M--;

            if (N == M) {
                U = N;
                break;
            }
        }
        printf("%d %d\n", U, T);
    }
    return 0;
}