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

	int flag = 0;	// �н����� üĿ�� ����ߴ��� Ȯ���ϴ� ����

	while (flag == 0) {
		cout << "�н����� �Է�(8���� �̻�, ��ҹ���/����/Ư������ ����):";
		cin >> password;

		cout << "\n�Էµ� �н����� : " << password << endl;

		int result = passwordChecker(password);

		switch (result) {
			case 1:
				strncpy(password_buf, "8���� �̻��̾�� �մϴ�.\n", sizeof(password_buf));
				break;
			case 2:
				strncpy(password_buf, "���� �빮�ڰ� �ϳ� �̻��̾�� �մϴ�.\n", sizeof(password_buf));
				break;
			case 3:
				strncpy(password_buf, "���� �ҹ��ڰ� �ϳ� �̻��̾�� �մϴ�.\n", sizeof(password_buf));
				break;
			case 4:
				strncpy(password_buf, "���ڰ� �ϳ� �̻��̾�� �մϴ�.\n", sizeof(password_buf));
				break;
			case 5:
				strncpy(password_buf, "Ư�����ڰ� �ϳ� �̻��̾�� �մϴ�.\n", sizeof(password_buf));
				break;
			default:
				strncpy(password_buf, "��Ģ�� �´� �н������Դϴ�.\n", sizeof(password_buf));
				flag = 1;	// �ݺ��� Ż������ ����
				break;				
		}
		printf(password_buf);
	}
}

int passwordChecker(char password[])			// �Է¹��� �н����带 �˻��Ͽ� ������ ��������� ��ȯ
{
	int checkUpper = 0;
	int checkLower = 0;
	int checkDigit = 0;
	int checkSpecial = 0;

	if (strlen(password) < 8) return 1;			// �н����� ���̰� 8�ڸ����� ������ ������� 1
	for (int i = 0; i < strlen(password); i++) {
		if (isupper(password[i]))
			checkUpper = 1;						// �н����忡 ���� �빮�ڰ� ������ ������� 2
		else if (islower(password[i]))
			checkLower = 1;						// �н����忡 ���� �ҹ��ڰ� ������ ������� 3
		else if (isdigit(password[i]))
			checkDigit = 1;						// �н����忡 �����ڰ� ������ ������� 4
		else
			checkSpecial = 1;					// �н����忡 Ư�����ڰ� ������ ������� 5
	}

	if (checkUpper == 0) return 2;
	if (checkLower == 0) return 3;
	if (checkDigit == 0) return 4;
	if (checkSpecial == 0) return 5;
	return 0;									// �н����尡 ��� ������ �����ϸ� ������� 0
}