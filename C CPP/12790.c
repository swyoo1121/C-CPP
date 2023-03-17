#include <stdio.h>

int main() {
    int T, hp, mp, at, df, ehp, emp, eat, edf;

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d %d %d %d %d %d %d", &hp, &mp, &at, &df, &ehp, &emp, &eat, &edf);

        if (hp + ehp < 1) hp = 1;
        else hp += ehp;

        if (mp + emp < 1) mp = 1;
        else mp += emp;

        if (at + eat < 0) at = 0;
        else at += eat;

        df += edf;

        printf("%d\n", hp + 5 * mp + 2 * at + 2 * df);
    }
    return 0;
}