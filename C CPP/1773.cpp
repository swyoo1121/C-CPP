#include <iostream>

using namespace std;

int N, C, record[2000001] = {0, };

int main() {
    int result = 0, input;

    cin >> N >> C;

    for (int i = 1; i <= N; i++) {
        cin >> input;

        int index = 1;
        
        while (index <= C) {
            if (index % input == 0) record[index] = 1;
            index++;
        }
    }

    for (int i = 1; i <= C; i++) {
        if (record[i] == 1) result++;
    }
    
    cout << result << '\n';
    return 0;
}