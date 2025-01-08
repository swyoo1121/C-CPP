#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> vec;
    int current_number, temp;
    
    cin >> n;    
    cin >> current_number;

    for (int i = 0; i < n-1; i++) {
        cin >> temp;
        vec.emplace_back(temp - current_number);
        current_number = temp;
    }

    int current_gcd = vec[0];
    for (const auto& it : vec) {
        current_gcd = gcd(current_gcd, it);
    }

    int count = 0;
    for (const auto& it : vec) {
        count += it / current_gcd - 1;
    }
    cout << count << '\n';
}
