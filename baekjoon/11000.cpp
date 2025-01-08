#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int N, result = 0;
vector<pair<int, int>> v;
priority_queue< int, vector<int>, greater<int>> pq;

int main()
{

    cin >> N;

    for (int iter = 0; iter < N; iter++)
    {
        int S, T;
        cin >> S >> T;
        v.push_back(make_pair(S, T));
    }

    sort(v.begin(), v.end());

    for (auto i = v.begin(); i != v.end(); i++)
    {
        pq.push(i->second);
        if (i->first >= pq.top()) pq.pop();
    }
    result = pq.size();

    cout << result << endl;
    return 0;
}