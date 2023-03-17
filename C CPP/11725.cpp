#include <iostream>
#include <vector>

using namespace std;
int n;

vector<int> graph[100001];
int parent[100001];

void dfs(int from) {
	
	for (int i = 0; i < graph[from].size(); i++) {
		int to = graph[from][i];
		if (parent[to] == 0) {
			parent[to] = from;
			dfs(to);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	dfs(1);
	
	for (int i = 2; i <= n; i++) {
		cout <<parent[i]<< '\n';
	}

	return 0;
}