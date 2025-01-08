#include <iostream>

using namespace std;

int main() {
    int N, x, y, max_x = -10001, min_x = 10001, max_y = -10001, min_y = 10001, result;

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        
        if (min_x > x) min_x = x;
        if (max_x < x) max_x = x;
        if (min_y > y) min_y = y;
        if (max_y < y) max_y = y;
    }

    cout << (max_x - min_x) * (max_y - min_y) << endl;
    return 0;
}