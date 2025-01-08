#include <iostream>

using namespace std;

int main() {
	long long X, Y;

	cin >> X >> Y;
	long long Z = Y * 100 / X;

	if (Z >= 99) {
		cout << "-1" << endl;
		return 0;
	}

	long long high = 1000000000;
	long long low = 0;
	long long mid;

	while (low <= high) {
		mid = (high + low) / 2;
		long long tmp = (Y + mid) * 100 / (X + mid);

		if (Z < tmp) {
			high = mid - 1;
		}
		else {	
			low = mid + 1;
		}
	}

	cout << low << endl;
    return 0;
}