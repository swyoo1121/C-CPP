#include <iostream>

using namespace std;

int main()
{
    int a, b, c, result;
    cin >> a >> b >> c;

    if (a > b)
    {
        int swap = a;
        a = b;
        b = swap;
    }
    if (b > c)
    {
        int swap = b;
        b = c;
        c = swap;
    }
    if (a > b)
    {
        int swap = a;
        a = b;
        b = swap;
    }

    if (a + b > c)
        result = a + b + c;
    else
        result = 2 * (a + b) - 1;

    cout << result << endl;
    return 0;
}