#include <iostream>
#include <cmath>

/*
처음 풀때는 단순히 두 점이 원 안에만 있는지를 체크하다보니, 두 점 모두 원 안에 있을 경우를 계산하지 않았다.
구현과정에서 조금 실수가 있어서 4트에 성공.
*/

using namespace std;

int main()
{
    int T, n, count, flag;
    double x1, y1, x2, y2, cx, cy, r;

    cin >> T;

    for (int iter = 0; iter < T; iter++)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> n;
        count = 0;

        for (int iter2 = 0; iter2 < n; iter2++)
        {
            cin >> cx >> cy >> r;
            flag = 0;
            double dist1 = pow((x1 - cx), 2) + pow((y1 - cy), 2);
            double dist2 = pow((x2 - cx), 2) + pow((y2 - cy), 2);
            if ( dist1 < pow(r, 2) && dist2 < pow(r, 2)) {
                continue;
                }
            else if ( dist1 < pow(r, 2) || dist2 < pow(r, 2))
                count++;
        }
        cout << count << endl;
    }
}
