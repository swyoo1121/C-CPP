#include <iostream>
#include <algorithm>

using namespace std;

int student[10001];

int main() {
    int n;
    int min = 0;

    cin >> n;

    for (int i = 0; i < 2 * n; i++) {
        cin >> student[i];
    }
    
    sort(student, student + 2 * n);
    
    min = student[0] + student[2 * n - 1];
    
    for (int i = 0; i < 2 * n; i++) {
        int target = student[i] + student[2 * n - i - 1];
        
        if (min > target) {
            min = target;
        }
    }
    
    cout << min << endl;
    return 0;
}

