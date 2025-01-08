#include <iostream>

using namespace std;

int main() {
    int N, Q, checker, index, target, B[101], T[10001];
    
    cin >> N >> Q;
    index = 0;

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++) {
        checker = 0;
        while (checker < B[i]) {
            T[index] = i + 1;
            index++;
            checker++;
        }
    }

    for (int i = 0; i < Q; i++) {
        cin >> target;
        cout << T[target] << endl;
    }
    return 0;
}