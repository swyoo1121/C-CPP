#include <stdio.h>

int main(void) {
    int T, flag;
    char A[105], B[105], alpha[26] = {0, };

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        flag = 0;
        scanf("%s %s", &A, &B);

        for (int j = 0; A[j] != '\0'; j++) {
            alpha[A[j] - 'a']++;
        }

        for (int j = 0; B[j] != '\0'; j++) {
            alpha[B[j] - 'a']--;
        }

        for (int j = 0; j < 26; j++) {
            if (alpha[j] != 0) {
                flag = 1;
                alpha[j] = 0;
            }
        }

        if (flag == 0) printf("%s & %s are anagrams.\n", A, B);
        else printf("%s & %s are NOT anagrams.\n", A, B);
    }

    return 0;
}