#include <stdio.h>

int main() {
    int length;
    char L[51];
    long long int result = 0, R = 1;

    scanf("%d", &length);
    scanf("%s", &L);

    for (int i = 0; i < length; i++) {
		result = (result + (L[i] - 'a' + 1) * R) % 1234567891;
		R = (R * 31) % 1234567891;
	}

	printf("%lld\n", result);
    return 0;
}