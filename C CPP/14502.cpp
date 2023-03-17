#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[9][9];
bool visit[9][9];
int virus, wall;
int ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
vector<pair<int, int>> way;
queue<pair<int, int>> q;

int BFS() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			visit[i][j] = false;

	int cnt = virus;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (map[i][j] == 2) q.push({ i,j });

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + dx[i];
			int next_y = now_y + dy[i];

			if (next_x < 1 || next_x > N || next_y < 1 || next_y > M)
				continue;

			if (!visit[next_x][next_y] && map[next_x][next_y] == 0) {
				q.push({ next_x ,next_y });
				visit[next_x][next_y] = true;
				cnt++;
			}
		}
	}

	return N * M - (cnt + wall + 3);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			switch (map[i][j]){
			case 0: way.push_back({i,j}); break;
			case 1: wall++; break;
			case 2: virus++; break;
			}
		}
    }
			
	for (int i = 0; i < way.size(); i++) {
		for (int j = i + 1; j < way.size(); j++) {
			for (int k = j + 1; k < way.size(); k++) {
				map[way[i].first][way[i].second] = 1;
				map[way[j].first][way[j].second] = 1;
				map[way[k].first][way[k].second] = 1;
				
				ans = max(ans, BFS()); 
				
				map[way[i].first][way[i].second] = 0;
				map[way[j].first][way[j].second] = 0;
				map[way[k].first][way[k].second] = 0;
			}
        }
    }
    
	cout << ans << '\n';
    return 0;
}