#include <stdio.h>

int main() {
    int T, input;

    scanf("%d", &T);

    for (int testcase = 0; testcase < T; testcase++) {
        scanf("%d", &input);

        for (int i = 1; i <= input; i++) {
            for (int j = 1; j <= input; j++) {
                if (i == 1 || i == input || j == 1 || j == input) printf("#");
                else printf("J");
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}