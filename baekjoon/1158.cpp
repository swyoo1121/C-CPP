#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N, K, round = 1;
    queue<int> q;

    cin >> N >> K;

    for (int iter = 1; iter <= N; iter++)
    {
        q.push(iter);
    }
    cout << '<';

    while (!q.empty())
    {
        if (round == K)
        {
            if (q.size() != 1)
                cout << q.front() << ", ";
            else
                cout << q.front();

            q.pop();
            round = 1;
        }
        else
        {
            round++;
            q.push(q.front());
            q.pop();
        }
    }

    cout << '>' << '\n';
    return 0;
}