#include <iostream>
#include <cstdlib>
#include <cmath>

#define PI 3.1415926535897

using namespace std;

int main() {
    int L;
    cin >> L;

    cout.precision(15);

    cout << (double)L * (double)L * sin(120 * PI / 180) / 2 << endl;
    return 0;
}