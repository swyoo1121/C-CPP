#include <stdio.h>

int main() {
    int N, new_score, P, cnt = 0, rank = 1;
    int score[51];

    scanf("%d %d %d", &N, &new_score, &P);

    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
    }

    for (int i = 0; i < N; i++) {
        if (score[i] > new_score) rank++;
        else if (score[i] == new_score) rank = rank;
        else break;

        cnt++;
    }

    if (cnt == P) rank = -1;
    if (N == 0) rank = 1;

    printf("%d\n", rank);
    return 0;
}