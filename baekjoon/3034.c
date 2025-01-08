#include <stdio.h>

int main (void) {
    int N, W, H, input;

    scanf("%d %d %d", &N, &W, &H);

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);

        if (input * input > W * W + H * H) printf("NE\n");
        else printf("DA\n");
    }

    return 0;
}