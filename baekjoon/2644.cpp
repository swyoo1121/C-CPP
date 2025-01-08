#include <iostream>
#include <vector>

using namespace std;

vector<int> family[101];
int visited[101] = {0, };
int n, start, finish, m, x, y, result = 0;

void dfs(int now, int num) {
	visited[now] = 1;
	if (now == finish) {
		result = num;
	}
	for (int i = 0; i < family[now].size(); i++) {
		int next = family[now][i];
		if (!visited[next]) {
			dfs(next, num+1);
		}
	}
}

int main() {
    cin >> n;
    cin >> start >> finish;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }

    dfs(start, 0);

    if (result != 0) cout << result << endl;
    else cout << "-1" << endl;

    return 0;
    
}