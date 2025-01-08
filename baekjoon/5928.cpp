#include <iostream>

using namespace std;

int main() {
    int D, H, M, result = 0;
    cin >> D >> H >> M;

    result = D * 1440 + H * 60 + M;
    result -= 11 * 1440 + 11 * 60 + 11;

    if (result >= 0) cout << result << endl;
    else cout << -1 << endl;

}