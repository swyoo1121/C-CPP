#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

int visited[9] = {0, };
int ans[9];
map<int, int> inputs;
int N, M, input;

bool compare(int a, int b) {
    return a < b;
}
    
void recursion(int x) {
    if (x == M + 1)	{
		for (int i = 1; i <= M; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				ans[x] = inputs[i];
				recursion(x + 1);
				visited[i] = 0;
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int typing[9];
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> typing[i];
    }

    sort(typing, typing + N, compare);

    for (int i = 1; i <= N; i++) {
        inputs.insert(make_pair(i, typing[i - 1]));
    }
    recursion(1);
    return 0;
}
