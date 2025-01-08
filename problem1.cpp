#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	cout << "(1)" << endl; // 1번 피라미드

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			cout << '*';	// n번째 줄에 *을 n번 입력하도록 반복문 선언
		}
		if (i == 5) break;	// 마지막 줄에는 줄바꿈 생략
		cout << endl;
	}

	cout << "\n" << endl;


	cout << "(2)" << endl; // 2번 피라미드
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << '*';	// n번째 줄에 *을 2*n-1번 입력하도록 반복문 선언 (1,3,5,7,9)
		}
		if (i == 5) break;	// 마지막 줄에는 줄바꿈 생략
		cout << endl;
	}
	
	cout << "\n" << endl;


	cout << "(3)" << endl; // 3번 피라미드
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 5; j >= i; j--) {
			cout << '*';	// n번째 줄에 *을 6-n번 입력하도록 반복문 선언
		}
		if (i == 5) break;	// 마지막 줄에는 줄바꿈 생략
		cout << endl;
	}

	cout << "\n" << endl;


	cout << "(4)" << endl; // 4번 피라미드
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 5; j >= 1; j--) {
			if (j > i) cout << ' ';
			else cout << '*'; // n번째 줄에 공백을 5-n번 입력하고, n번 *을 입력하도록 반복문 선언
		}
		if (i == 5) break;	// 마지막 줄에는 줄바꿈 생략
		cout << endl;
	}

	cout << "\n" << endl;


	cout << "(5)" << endl; // 5번 피라미드
	
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j <= 5 - i || j >= 5 + i) cout << ' ';
			else cout << '*'; // n번째 줄에 공백을 좌우로 5-n번 입력하고, 2*n-1번 *을 입력하도록 반복문 선언 (1,3,5,7,9)
		}
		if (i == 5) break;	// 마지막 줄에는 줄바꿈 생략
		cout << endl;
	}

	cout << "\n" << endl;


	cout << "(6)" << endl; // 6번 피라미드
	
	for (int i = 5; i >= 1; i--) {
		for (int j = 1; j <= 9; j++) {
			if (j <= 5 - i || j >= 5 + i) cout << ' ';
			else cout << '*'; // n번째 줄에 공백을 좌우로 n-1번 입력하고, 11-2*n번 *을 입력하도록 반복문 선언 (9,7,5,3,1)
		}
		if (i == 1) break;	// 마지막 줄에는 줄바꿈 생략
		cout << endl;
	}

	cout << "\n" << endl;


	return 0;
}