#include <iostream>
#include <string>

using namespace std;

int n = 1, m = 1, i, t, f;
string s;

int main() {
	cin >> s;
	for (i = 1; i < s.size(); f += n == m, n = 1, m = 1, i++) {
		for (t = 0; t < i; t++) n *= (s[t] - 48);
		for (t = i; t < s.size(); t++) m *= (s[t] - 48);
	}
	printf("%s", f ? "YES" : "NO");
}