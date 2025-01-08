#include <stdio.h>

int main() {
    int N, count, input, A[5] = {0, }, B[5] = {0, };

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &count);
        for (int j = 0; j < count; j++) {
            scanf("%d", &input);
            A[input]++;
        }

        scanf("%d", &count);
        for (int j = 0; j < count; j++) {
            scanf("%d", &input);
            B[input]++;
        }

        if (A[4] > B[4]) printf("A\n");
        else if (A[4] < B[4]) printf("B\n");
        else {
            if (A[3] > B[3]) printf("A\n");
            else if (A[3] < B[3]) printf("B\n");
            else {
                if (A[2] > B[2]) printf("A\n");
                else if (A[2] < B[2]) printf("B\n");
                else {
                    if (A[1] > B[1]) printf("A\n");
                    else if (A[1] < B[1]) printf("B\n");
                    else printf("D\n");
                }
            }
        }

        for (int j = 0; j < 5; j++) {
            A[j] = 0;
            B[j] = 0;
        }
    }
    
    return 0;
}