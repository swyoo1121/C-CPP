#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A_in, B_in;
vector<int> A;
vector<int> B;

int main() {
    cin >> A_in >> B_in;

    for (int iter = 0; iter < A_in; iter++) {
        int input;
        cin >> input;
        A.push_back(input);
    }

    for (int iter = 0; iter < B_in; iter++) {
        int input;
        cin >> input;
        B.push_back(input);
    }

    sort(A.begin(), A.end()); // 문제 설명에는 안나왔지만 중복원소 + 무작위 순서의 케이스 때문에 정렬 및 제거 필요
    sort(B.begin(), B.end());

    A.erase(unique(A.begin(), A.end()), A.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    vector<int> inter(A.size() + B.size());
    auto iter = set_intersection(A.begin(), A.end(), B.begin(), B.end(), inter.begin());
    inter.erase(iter, inter.end());

    cout << A.size() + B.size() - 2 * inter.size() << endl;
    return 0;
}