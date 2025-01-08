#include <iostream>

using namespace std;

int main() {
	int K, N;
    long long int left, right, mid, cnt, max = 0;
	long long int arr[10001];

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}

	left = 1, right = max, mid = 0, cnt = 0;

	while (right - left > 1) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) cnt += arr[i] / mid;

		if (cnt < N) right = mid;
		else left = mid;
	}

    cnt = 0;

    for (int i = 0; i < K; i++) cnt += arr[i] / right;

    if (cnt == N) cout << right << '\n';
    else cout << left << '\n';
    
    return 0;
}