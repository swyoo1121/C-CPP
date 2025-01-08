#include <iostream>

using namespace std;

long long A, B;

int GCD(long long a, long long b){
    return b == 0 ? a : GCD(b, a%b);
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> A >> B;

    cout << A * B / GCD(A,B) << '\n';
    return 0;
}