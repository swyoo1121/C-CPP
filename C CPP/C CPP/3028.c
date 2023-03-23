#include <stdio.h>

int main() {
    int cup[3] = {1, 0, 0};
    char change[51];

    scanf("%s", &change);

    for (int i = 0; change[i] != '\0'; i++) {
        if (change[i] == 'A') {
            int swap = cup[0];
            cup[0] = cup[1];
            cup[1] = swap;
        }
        else if (change[i] == 'B') {
            int swap = cup[1];
            cup[1] = cup[2];
            cup[2] = swap;
        }
        else {
            int swap = cup[0];
            cup[0] = cup[2];
            cup[2] = swap;
        }
    }

    if (cup[0] == 1) printf("1\n");
    else if (cup[1] == 1) printf("2\n");
    else printf("3\n");

    return 0;
}