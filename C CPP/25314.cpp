#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    int rec = (N - 1)/4;

    for (int iter = 0; iter < rec; iter++) {
        cout << "long ";
    }

    cout << "long int" << '\n';
    return 0;
}