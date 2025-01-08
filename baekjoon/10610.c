#include <stdio.h>

char N[100001];

int main(void) {
    int iszero, sum, replay;
    int num[10] = {0, };

    iszero = 0;
    sum = 0;
    replay = 9;

    scanf("%s", &N);

    for (int i = 0; N[i] != '\0'; i++) {
        if (N[i] == '0') iszero = 1;
        num[N[i] - '0']++;

        sum += (int)(N[i] - '0');
    }

    if (sum % 3 != 0 || iszero == 0) printf("-1");
    else { 
        while (replay >= 0) {
            if (num[replay] > 0) {
                printf("%d", replay);
                num[replay]--;
            }
            else replay--;
        }
    }
    return 0;
}