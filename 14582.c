#include <stdio.h>

int main() {
    int gem = 0, gul = 0, flag = 1;
    int score[2][9];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &score[i][j]);            
        }
    }

    for (int i = 0; i < 9; i++) {
        gem += score[0][i];
        if (gem > gul) flag = 0;
        gul += score[1][i];
    }
    
    if (flag == 0 && gem < gul) printf("Yes");
    else printf("No");

    return 0;
}