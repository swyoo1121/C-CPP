#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x[4], y[4], result = 0;
    
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x, x + 4);
    sort(y, y + 4);

    if (x[3] - x[0] > y[3] - y[0]) result = x[3] - x[0];
    else result = y[3] - y[0];

    cout << result * result << endl;

}