#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, input, M;
    vector<int> v;

    cin >> N;
    for (int iter = 0; iter < N; iter++) {
        cin >> input;
        v.push_back(input);
    }
    cin >> M;

    sort(v.begin(), v.end());

    

}