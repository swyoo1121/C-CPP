#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int DP[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	int n, result = 0;

	cin >> n;
	v.emplace_back(0, 0);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				if (DP[j] >= DP[i])
					DP[i] = DP[j] + 1;
			}
		}
		result = max(result, DP[i]);
	}
    
	cout << n - result << '\n';
	return 0;
}