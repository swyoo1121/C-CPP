#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 100001

int N, K;
bool visited[MAX];

int BFS (int N, int K) {
	queue<pair <int, int>> q;
	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();

		if (x == K)	return time;

		if (x + 1 < MAX && !visited[x + 1]) {
			q.push(make_pair(x + 1, time + 1));
			visited[x + 1] = true;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push(make_pair(x - 1, time + 1));
			visited[x - 1] = true;
		}
		if (x * 2 < MAX && !visited[x * 2]) {
			q.push(make_pair(x * 2, time + 1));
			visited[x * 2] = true;
		}
	}
}

int main() {
	cin >> N >> K;
	
	cout << BFS(N, K) << endl;
	return 0;
}