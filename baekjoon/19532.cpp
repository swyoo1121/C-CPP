#include <iostream>

using namespace std;

int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    double x = (c * e - b * f) / (a * e - b * d);
    double y = (c * d - a * f) / (b * d - a * e);

    x = (int)x;
    y = (int)y;
    
    cout << x << " " << y << endl;
    return 0;
}