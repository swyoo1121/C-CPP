#include <iostream>
#include <cmath>

using namespace std;

int n;
unsigned int input;

int solve (unsigned int target) {
    unsigned int root = (int)sqrt(target);

    if (target <= 1) return 1; // 1 입력시 주의

    for (int iter = 2; iter < root + 1; iter++) {
        if (target % iter == 0) return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    while(n--) {
        cin >> input;
        while(true) {
            if(solve(input) != 0) input++;
            else break;
        }

        cout << input << endl;
    }

    return 0;
}