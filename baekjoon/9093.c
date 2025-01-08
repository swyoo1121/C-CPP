#include <stdio.h>
#include <stdlib.h>

int main() {
    int T, length;
    char word[21], sentence[1001];

    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++) {
        gets(sentence);
        length = 0;

        for (int j = 0; sentence[j] != '\0'; j++) {
            if (sentence[j] != ' ') {
                word[length] = sentence[j];
                length++;
            }
            else {
                while (length > 0)  {
                    printf("%c", word[length - 1]);
                    length--;
                }
                printf(" ");
            }
        }

        for (int j = length - 1; j >= 0; j--) {
            printf("%c", word[j]);
        }

        printf("\n");
    }
    return 0;
}