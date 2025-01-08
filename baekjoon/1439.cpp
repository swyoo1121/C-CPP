    #include <iostream>
    #include <string>

    using namespace std;

    int main() {
        string S;
        int result = 1;

        cin >> S;

        for (int i = 1; i < S.length(); i++) {
            if (S[i] != S[i-1]) result++;
        }

        cout << result / 2 << endl;
        return 0;
    }