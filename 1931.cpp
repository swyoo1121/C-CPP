#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, end, begin;
    int value[10];

    vector<pair<int, int>> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> begin >> end;
        v.push_back(make_pair(end, begin));
    }

    sort(v.begin(), v.end());

    int time = v[0].first;
    int count = 1;
    for (int i = 1; i < N; i++)
    {
        if (time <= v[i].second)
        {
            count++;
            time = v[i].first;
        }
    }

    cout << count;
}
