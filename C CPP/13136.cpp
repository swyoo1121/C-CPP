#include <iostream>

using namespace std;

int main() {
    long long int R, C, N, result = 1;
    cin >> R >> C >> N;
    
    if (R % N != 0) result *= (R / N) + 1;
    else result *= R / N;

    if (C % N != 0) result *= (C / N) + 1;
    else result *= C / N;

    cout << result << endl;
    return 0;
}