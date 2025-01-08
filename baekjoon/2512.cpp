#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, input, M, sum = 0, result;
    int low, mid, high;
    vector<int> v;

    cin >> N;
    for (int iter = 0; iter < N; iter++)
    {
        cin >> input;
        v.push_back(input);
        sum += input;
    }
    cin >> M;

    sort(v.begin(), v.end());
    low = 0;
    high = v.at(N - 1);

    while (low <= high)
    {
        mid = (low + high) / 2;
        sum = 0;

        for (int iter = 0; iter < N; iter++)
        {
            if (mid > v.at(iter))
                sum += v.at(iter);
            else
                sum += mid;
        }

        if (M >= sum)
        {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    cout << result << endl;
    return 0;
}