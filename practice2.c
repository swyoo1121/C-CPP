#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int rounds;
	scanf("%d", &rounds);

	for (int i = 1; i <= rounds; i++) {
		for (int j = 1; j < rounds * 2; j++) {
			int flag = 0;
			for (int k = rounds; k >= 3; k /= 2) {
				if (i % 3 == 1) {   // first line
					if (j <= rounds - i || j >= rounds + i) {
						flag = 1;
						break;
					}
					if (j % k != 0) {
						flag = 1;
						break;
					}
				}
				else if (i % 3 == 2) {  // second line
					if (j <= rounds - i || j >= rounds + i) {
						flag = 1;
						break;
					}
					if (j % k == 0) {
						flag = 1;
						break;
					}
				}
				else {  // third line
					if (j <= rounds - i || j >= rounds + i) {
						flag = 1;
						break;
					}
					if (j % (k / 2) == 0) {
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}
