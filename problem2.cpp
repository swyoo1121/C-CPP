#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define MAX 30

using namespace std;

void swap(int v[], int i, int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
} 

void sort(int v[], int left, int right)	// 선택 정렬로 구현
{
	for (int i = left; i < MAX; i++) {	// n번째 순서에 배열의 n번째 숫자 확정
		for (int j = i + 1; j < MAX; j++) {
			if (v[i] > v[j]) swap(v, i, j);	// 더 낮은 숫자가 있을 경우 n번째 위치에 해당 숫자로 바꿈
		}
	}
} 

int main()
{
	int v[MAX];

	srand(time(NULL));

	for (int i = 0; i < MAX; i++) {
		int input = rand();	// rand() 함수를 이용하여 숫자 생성
		v[i] = input;	// 미리 선언된 배열 v에 숫자 저장
		cout << v[i] << '\t';	// 숫자 출력 후 공백 출력
		if ((i+1) % 10 == 0) cout << endl;	// 10번째 줄마다 줄바꿈
	}

	cout << "\nsorting\n" << endl;
	
	sort(v, 0, MAX);

	for (int i = 0; i < MAX; i++) {
		cout << v[i] << '\t';
		if ((i+1) % 10 == 0) cout << endl;	// 정렬 후 결과 출력력
	}

	cout << endl;
	
	return 0;
}