#include <stdio.h>

int main(void) {
    char input[8];
    int max, count;

    for (int i = 0; i < 3; i++) {
        scanf("%s", &input);

        max = 0;
        count = 1;
        for (int j = 0; j < 7; j++) {
            if (input[j] == input[j+1]) {
                count++;
            }
            else {
                if (max < count) max = count;
                count = 1;
            }
        }

        if (max < count) max = count;

        printf("%d\n", max);
    }

    return 0;
}