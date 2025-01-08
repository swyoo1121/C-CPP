#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

int passwordChecker(char password[]);

int main(int argc, char* argv[])
{
	char password[30];
	char password_buf[256];

	int flag = 0;	// 패스워드 체커를 통과했는지 확인하는 변수

	while (flag == 0) {
		cout << "패스워드 입력(8글자 이상, 대소문자/숫자/특수문자 포함):";
		cin >> password;

		cout << "\n입력된 패스워드 : " << password << endl;

		int result = passwordChecker(password);

		switch (result) {
			case 1:
				strncpy(password_buf, "8글자 이상이어야 합니다.\n", sizeof(password_buf));
				break;
			case 2:
				strncpy(password_buf, "영문 대문자가 하나 이상이어야 합니다.\n", sizeof(password_buf));
				break;
			case 3:
				strncpy(password_buf, "영문 소문자가 하나 이상이어야 합니다.\n", sizeof(password_buf));
				break;
			case 4:
				strncpy(password_buf, "숫자가 하나 이상이어야 합니다.\n", sizeof(password_buf));
				break;
			case 5:
				strncpy(password_buf, "특수문자가 하나 이상이어야 합니다.\n", sizeof(password_buf));
				break;
			default:
				strncpy(password_buf, "규칙에 맞는 패스워드입니다.\n", sizeof(password_buf));
				flag = 1;	// 반복문 탈출조건 성립
				break;				
		}
		printf(password_buf);
	}
}

int passwordChecker(char password[])			// 입력받은 패스워드를 검사하여 정수형 결과값으로 반환
{
	int checkUpper = 0;
	int checkLower = 0;
	int checkDigit = 0;
	int checkSpecial = 0;

	if (strlen(password) < 8) return 1;			// 패스워드 길이가 8자리보다 적으면 결과값은 1
	for (int i = 0; i < strlen(password); i++) {
		if (isupper(password[i]))
			checkUpper = 1;						// 패스워드에 영문 대문자가 없으면 결과값은 2
		else if (islower(password[i]))
			checkLower = 1;						// 패스워드에 영문 소문자가 없으면 결과값은 3
		else if (isdigit(password[i]))
			checkDigit = 1;						// 패스워드에 숫자자가 없으면 결과값은 4
		else
			checkSpecial = 1;					// 패스워드에 특수문자가 없으면 결과값은 5
	}

	if (checkUpper == 0) return 2;
	if (checkLower == 0) return 3;
	if (checkDigit == 0) return 4;
	if (checkSpecial == 0) return 5;
	return 0;									// 패스워드가 모든 조건을 만족하면 결과값은 0
}