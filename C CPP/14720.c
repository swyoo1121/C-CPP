#include <stdio.h>

int main() {
    int N, count = 0, flag = 0, input;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        if (flag == 0 && input == 0) {
            count++;
            flag = 1;
        }
        else if (flag == 1 && input == 1) {
            count++;
            flag = 2;
        }
        else if (flag == 2 && input == 2) {
            count++;
            flag = 0;
        }
        else continue;
    }

    printf("%d\n", count);
    return 0;
}