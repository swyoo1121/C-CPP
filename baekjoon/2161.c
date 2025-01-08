#include <stdio.h>

int cards[5000];

int main() {
    int N, index, last;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        cards[i] = i;
    }

    index = 1;
    last = N;

    while (N > 0) {
        printf("%d ", cards[index]);
        last++;
        index++;
        cards[last] = cards[index];
        index++;
        N--;
    }

    return 0;

}