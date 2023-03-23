#include <iostream>
#include <string>

using namespace std;

int main() {
    int result = 1, alpha = 26, number = 10;
    string car;

    cin >> car;

    if (car[0] == 'c') result *= alpha;
    else result *= number;

    for (int i = 1; i < car.length(); i++) {
        if (car[i] == 'c') {
            if (car[i-1] == 'c') {
                alpha = 25;
                result *= alpha;
            }
            else {
                alpha = 26;
                result *= alpha;
            }
        }
        else {
            if (car[i-1] == 'd') {
                number = 9;
                result *= number;
            }
            else {
                number = 10;
                result *= number;
            }
        }
    }

    cout << result << endl;
    return 0;
}