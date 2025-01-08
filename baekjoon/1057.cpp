#include <iostream>

using namespace std;

int main() {
    int N, kim, lim, count = 0;

    cin >> N >> kim >> lim;

    while (kim != lim) {
        count++;
        kim = (kim + 1) / 2;
        lim = (lim + 1) / 2;
    }

    cout << count << endl;
    return 0;
}