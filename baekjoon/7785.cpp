#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<string, int> M;
set<string> S;
int N;
string name, ent;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> ent;
		if (ent == "enter")
			M[name] = 1;
		else
			M[name] = 0;
		S.insert(name);
	}

	auto iter = S.end();
	int flag = 0;

	while (1) {
		iter--;
		if (iter == S.begin()) flag = 1;
		if (M[*iter] == 1)
			cout << *iter << "\n";
		if (flag == 1) break;
	}
}