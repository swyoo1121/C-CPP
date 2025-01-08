#include <iostream>

using namespace std;

int main() {
    int T, A, B, C, D, E, correct = 0;

    cin >> T;
    cin >> A >> B >> C >> D >> E;

    if (T == A) correct++;
    if (T == B) correct++;
    if (T == C) correct++;
    if (T == D) correct++;
    if (T == E) correct++;

    cout << correct << endl;
    return 0;
}