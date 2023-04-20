#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, K;

int checker(int x) {
    while (x > 0) {
        int fin = x % 10;
        if (fin == 5 || fin == 8) x /= 10;
        else return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        vector<int> A;
        vector<int> B;
        vector<int> C;
        int input, index = 0;
        vector<int> result;
    
        cin >> N;
        for (size_t i = 0; i < N; i++)
        {
            cin >> input;
            A.push_back(input);
        }
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());

        cin >> M;
        for (size_t i = 0; i < M; i++)
        {
            cin >> input;
            B.push_back(input);
        }
        sort(B.begin(), B.end());
        B.erase(unique(B.begin(), B.end()), B.end());

        cin >> K;
        for (size_t i = 0; i < K; i++)
        {
            cin >> input;
            C.push_back(input);
        }
        sort(C.begin(), C.end());
        C.erase(unique(C.begin(), C.end()), C.end());

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                for (int k = 0; k < C.size(); k++)
                {
                    int target = A[i] + B[j] + C[k];
                    if (checker(target) == 0 && find(result.begin(), result.end(), target) == result.end()) {
                        result.push_back(target);
                        index++;
                    }
                }
            }
        }

        cout << index << endl;
    }

    return 0;
}
