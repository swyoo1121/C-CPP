#include <iostream>
#include <map>

using namespace std;

int T, N, result, flag;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> N;
        result = 1;
        map<int, int> grade;

        for (int iter = 0; iter < N; iter++)
        {
            int a, b;
            cin >> a >> b;
            grade.insert(make_pair(a, b));
        }
        flag = grade[1];

        for (auto iter = grade.begin(); iter != grade.end(); iter++)
        {
            if (flag > iter->second)
            {
                flag = iter->second;
                result++;
            }
        }

        cout << result << endl;
    }
}