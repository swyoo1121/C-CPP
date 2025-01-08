#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (x % y == 0) return y;
    else return gcd(y, x % y);
}

int main() {
    int t, n, input[101];
    long long int answer;
    
    cin >> t;

    while (t-- > 0) {
        cin >> n;
        answer = 0;

        for (int iter = 0; iter < n; iter++) {
            cin >> input[iter];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (input[i] < input[j]) answer += gcd(input[j], input[i]);
                else answer += gcd(input[i], input[j]);
            }
        }

        cout << answer << '\n';
    }
}

/*
 흔한 유클리드 호제법 문제 중 하나. 워낙 재귀함수로 많이 풀어본 유형이라 그리 고민하는데 어렵지 않았다.
 다만 흔히 하는 실수인데 자료형을 int로 선언하여 결과값이 범위를 초과하는 경우를 간과했다.
 혹시 몰라 결과값과 gcd 함수를 long long int로 바꿔줬는데 2트만에 완료.
 근데 gcd 함수 자체는 input도 1,000,000을 넘지 않는다고 문제에 명시되어 있고 return값도 더 작을거라 int로 선언해도 문제는 없다.
 long long int를 사용하게 되면 메모리를 더 사용하지만 이정도는 메모리 사용 범위에 큰 기별도 안 간다는 사실을 다시 한번 확인.
*/