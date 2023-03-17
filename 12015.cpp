#include <iostream>

using namespace std;

int lis[1000001];
int sequence[1000001];
int idx;

void binarysearch(int s, int e, int num) {
	if (s >= e) {
		lis[s] = num;
		return;
	}

	int mid = (s + e) / 2;

	if (lis[mid] > num) binarysearch(s, mid, num);
	else if (lis[mid] < num) binarysearch(mid + 1, e, num);
	else if (lis[mid] == num) return;
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> sequence[i];

	idx = 1;
	lis[1] = sequence[1];

	for (int i = 2; i <= N; i++) {
		if (sequence[i] > lis[idx]) lis[++idx] = sequence[i];
		else binarysearch(1, idx, sequence[i]);
	}

	cout << idx << endl;
    return 0;
}