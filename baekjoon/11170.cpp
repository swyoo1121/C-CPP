#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		int N, M, res = 0;
		cin >> N >> M;

		for (int i = N; i <= M; i++) {
			for (auto& j : to_string(i)) {
				if (j == '0') res++;
            }
        }

		cout << res << '\n';
	}

	return 0;
}