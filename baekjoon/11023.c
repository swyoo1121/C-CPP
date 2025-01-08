#include <stdio.h>

int main(void) {
    int input, sum = 0;

    do {
        scanf("%d", &input);
        sum += input;
    } while (getc(stdin) == ' ');

    printf("%d", sum);

    return 0;

}