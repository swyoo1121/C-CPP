#include <stdio.h>

int main(void) {
    int N, answer, score, counter;

    scanf("%d", &N);

    score = 0;
    counter = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d", &answer);

        if (answer == 1) {
            counter++;
            score += counter;
        }
        else {
            counter = 0;
        }
    }

    printf("%d", score);

}