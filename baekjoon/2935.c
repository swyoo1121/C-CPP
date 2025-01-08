#include <stdio.h>
#include <string.h>

int main() {
    char operator, A[103], B[103], result[207] = {0, };
    int A_length, B_length;

    scanf("%s", &A);
    getchar();
    scanf("%c", &operator);
    getchar();
    scanf("%s", &B);

    A_length = strlen(A);
    B_length = strlen(B);

    if (operator == '+') {
        if (A_length > B_length) {
            A[A_length - B_length] = '1';
            strcpy(result, A);
        }
        else if (A_length < B_length) {
            B[B_length - A_length] = '1';
            strcpy(result, B);
        }
        else {
            strcpy(result, A);
            result[0] = '2';
        }
    }
    else if (operator == '*') {
        int zeros = A_length + B_length - 2;
        result[0] = '1';

        for (int i = 0; i < zeros; i++) {
            result[i+1] = '0';
        }
    }

    printf("%s\n", result);

    return 0;
}