#include <iostream>

using namespace std;

int main() {
    int me[10], opp[10];
    int A = 0, B = 0;

    for (int i = 0; i < 10; i++) {
        cin >> me[i];
    }
    
    for (int i = 0; i < 10; i++) {
        cin >> opp[i];
    }

    for (int i = 0; i < 10; i++) {
        if (me[i] > opp[i]) A++;
        else if (me[i] < opp[i]) B++;
        else continue;
    }

    if (A > B) cout << 'A' << endl;
    else if (A < B) cout << 'B' << endl;
    else cout << 'D' << endl;
}