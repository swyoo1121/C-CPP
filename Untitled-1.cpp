#include <iostream>

using namespace std;

int main() {
    int N, A, B;
    cin >> N;
    cin >> A >> B;

    if (N > A / 2 + B) cout << A / 2 + B << endl;
    else cout << N << endl;
    
}