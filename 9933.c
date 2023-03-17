#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[101][15], reverse[101][15] = {0, };
    int N, flag = 0, length, index;

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        gets(password[i]);
        length = strlen(password[i]);

        for (int j = 0; j < length; j++) {
            reverse[i][j] = password[i][length - j - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (strcmp(password[i], reverse[j]) == 0) {
                flag = 1;
                index = i;
                length = strlen(password[i]);
                flag = 1;
            }
        }
        if (flag == 1) break;
    }

    printf("%d %c\n", length, password[index][length / 2]);
    return 0;
}