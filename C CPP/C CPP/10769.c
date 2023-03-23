#include <stdio.h>

int main() {
    int happy, sad;
    char text[256];

    happy = 0;
    sad = 0;

    gets(text);

    for (int i = 0; text[i+2] != '\0'; i++) {
        if (text[i] == ':' && text[i + 1] == '-' && text[i + 2] == ')') happy++;
        if (text[i] == ':' && text[i + 1] == '-' && text[i + 2] == '(') sad++;
    }

    if (happy == 0 && sad == 0) printf("none\n");
    else if (happy > sad) printf("happy\n");
    else if (happy < sad) printf("sad\n");
    else printf("unsure\n");

    return 0;
}