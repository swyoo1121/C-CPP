#include <stdio.h>

int main() {
    int input, goal = 1;

    scanf("%d", &input);

    while (input != 1) {
        if (input % 2) input = input * 3 + 1;
        else input /= 2;

        goal++;
    }

    printf("%d\n", goal);
    return 0;
}