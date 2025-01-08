#include <iostream>

using namespace std;

int main() {
    int e, f, c, remedy, result = 0;

    cin >> e >> f >> c;

    remedy = e + f;

    while (remedy) {
        int change = remedy / c;
        result += change;
        remedy -= change * c;
        remedy += change;

        if (remedy / c == 0) break;
    }

    cout << result << endl;
    return 0;

}