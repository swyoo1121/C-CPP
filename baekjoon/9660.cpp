#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;

    if ((N % 7 == 0) || (N % 7 == 2)) cout << "CY" << endl;
    else cout << "SK" << endl;
    return 0;
}