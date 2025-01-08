#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ans[15];
int visited[15];
int input[15];
int k;
    
void recursion(int x) {
    if (x == 7)	{
        int flag = 0;
        for (int i = 1; i < 6; i++) {
            if (ans[i] > ans[i+1]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            for (int i = 1; i <= 6; i++) {
			printf("%d ", ans[i]);
		    }
		    printf("\n");
        }
	}
	else {
		for (int i = 1; i <= k; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				ans[x] = input[i];
				recursion(x + 1);
				visited[i] = 0;
			}
		}
	}
}

int main() {
    while(1) {
        scanf("%d", &k);

        if (k == 0) break;

        for (int i = 1; i <= k; i++) {
            scanf("%d", &input[i]);
            visited[i] = 0;
            ans[i] = 0;
        }

        recursion(1);
        printf("\n");
    }
    return 0;    
}
