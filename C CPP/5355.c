#include <stdio.h>

int main() {
    int T;
    double input;
    char c;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%lf", &input);

        while((c = getchar())) {
            if (c == '@') input *= 3;
            else if (c == '%') input += 5;
            else if (c == '#') input -= 7;
            else if (c == ' ') continue;
            else break;
        }

        printf("%.2lf\n", input);
    }

    return 0;
}