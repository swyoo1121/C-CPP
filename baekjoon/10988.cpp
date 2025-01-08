#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string word, copy;

    cin >> word;

    copy = word;

    reverse(copy.begin(), copy.end());

    if (word != copy) cout << 0 << endl;
    else cout << 1<< endl;

}

/*
C++에서 가장 유용하다고 생각하는 라이브러리인 algorithm에서 reverse를 이용하여 바로 해결
C언어와 달리 문자열을 나타내는 방법이 여러가지여서 vector를 쓰려다가 string도 reverse함수를 사용 가능한 것을 확인함.
다만 함수에 집착하다 보니 예전에 C로 구현한 투 포인터 알고리즘을 떠올리지 못했다는 것이 약간 아쉬움.
시간 복잡도는 reverse 함수와 투 포인터 알고리즘 모두 O(n)이지만, reverse는  기존의 객체(문자열, 벡터, 배열 등)를 변형한다는 것이 단점.
reverse_copy라는 함수도 있다는 것도 알음.
*/