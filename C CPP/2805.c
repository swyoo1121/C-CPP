#include <stdio.h>

int arr[1000001];

int main() {
	int N, M;
    long long int left, right, mid, cnt, max = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (max < arr[i]) max = arr[i];
	}

	left = 1, right = max, mid = 0, cnt = 0;

	while (right - left > 1) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int i = 0; i < N; i++) {
            if (arr[i] > mid) cnt += arr[i] - mid;
        }

		if (cnt < M) right = mid;
		else left = mid;
	}

    cnt = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > right) cnt += arr[i] - right;
    }

    if (cnt >= M) printf("%lld\n", right);

    cnt = 0; // If tree height is below 2, it needs extra testcase :<

    for (int i = 0; i < N; i++) {
        if (arr[i] > left) cnt += arr[i] - left;
    }

    if (cnt >= M) printf("%lld\n", left);
    else printf("%lld\n", left - 1);
    
    return 0;
}