#include <stdio.h>
#include <string.h>

int main() {
    int min = 52, count = 0;
    char A[51], B[51];
    scanf("%s %s", &A, &B);

    for (int i = 0; i <= strlen(B) - strlen(A); i++) {
        count = 0;
        for (int j = 0; j < strlen(A); j++) {
            if (A[j] != B[i + j]) count++;
        }

        if (min > count) min = count;
    }
    printf("%d\n", min);
    return 0;
}