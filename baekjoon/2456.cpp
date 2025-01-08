#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<pair<int, int>, pair<int, int>> arr[4];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, s, d;
		cin >> a >> s >> d;
		arr[0].first.first += a;
		if (a == 3)
			arr[0].first.second++;
		else if (a == 2)
			arr[0].second.first++;
		
		
		arr[1].first.first += s;
		if (s == 3)
			arr[1].first.second++;
		else if (s == 2)
			arr[1].second.first++;
		
		
		arr[2].first.first += d;
		if (d == 3)
			arr[2].first.second++;
		else if (d == 2)
			arr[2].second.first++;
	}
	arr[0].second.second = 1;
	arr[1].second.second = 2;
	arr[2].second.second = 3;

	sort(arr, arr + 3);

	if ((arr[2].first.first == arr[1].first.first) && (arr[2].first.second == arr[1].first.second) && (arr[2].second.first == arr[1].second.first)) {
	    cout << "0" << " " << arr[2].first.first;
	}
	else {
		cout << arr[2].second.second << " " << arr[2].first.first;
	}
	return 0;
}