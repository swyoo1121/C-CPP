#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, cnt = 0;
	map<string, int> m;

	cin >> n;
    
	while (n--) {
		string a, b;
		cin >> a >> b;
		if (a == "ChongChong") {
			m[a]++;
		}
		else if (b == "ChongChong") {
			m[b]++;
		}
		
        if (m[a] == 0 && m[b] != 0) {
			m[a]++;
			cnt++;
		}
		else if (m[a] != 0 && m[b] == 0) {
			m[b]++;
			cnt++;
		}
	}
    cnt++;
	cout << cnt << endl;
}