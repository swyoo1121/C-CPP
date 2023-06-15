#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M;
unordered_map<string, int> um;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
    {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        if (str.length() >= M)
            um[str]++;
    }

    vector<pair<string, int>> vec(um.begin(), um.end());
    sort(vec.begin(), vec.end(), cmp);

    for (auto p : vec)
        cout << p.first << "\n";

    return 0;
}