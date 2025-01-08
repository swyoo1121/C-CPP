#include <stdio.h>
#include <string.h>

int main() {
    int count, length, index;
    char input[10001];

    count = 2;

    while (1) {
        gets(input);
        if (strcmp("Was it a cat I saw?", input) == 0) break;

        index = 0;
        length = strlen(input);

        while (index < length) {
            printf("%c", input[index]);
            index += count;
        }

        count++;
        printf("\n");
    }
    return 0;
}