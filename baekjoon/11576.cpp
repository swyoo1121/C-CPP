#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int m, index = 0;
    int A, B, power, input[26], output[26], sum = 0;
    
    cin >> A >> B;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> input[i];
        index++;
    }

    power = 0;

    for (int i = index; i >= 1; i--) {
        sum += input[i] * pow(A, power);
        power += 1;
    }

    index = 1;
    power = 0;

    while (sum > 0) {
        output[index] = sum % B;
        sum /= B;
        index++;
    }

    for (int i = index - 1; i >= 1; i--) {
        cout << output[i] << ' ';
    }
    cout << endl;
    return 0;
}