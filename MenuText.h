#pragma once
#include <iostream>

using namespace std;

class UserCommunication {
public:
	string Choice = "Error";
	string Choice_6 = "6 - �������� �����������";
	string Choice_1 = "1 - �����������";
	string Choice_2 = "2 - ����� ����������";
	string Choice_3 = "3 - ���������� �� ����������";
	string Choice_4 = "4 - ������� ��������� ����������";
	string Choice_5 = "5 - ����� ������";
	short unsigned UserResp = 0;

	void ShowMenu() {
		cout << "�������� ���� ��� ����������� :" << endl
			
			<< Choice_1 << endl
			<< Choice_2 << endl
			<< Choice_3 << endl
			<< Choice_4 << endl
			<< Choice_5 << endl
			<< Choice_6 << endl
			<< "�������� �����: ";
	}
	short unsigned UserResponse() {
		cin >> UserResp;
		if (UserResp > 6 | UserResp < 0) { return UserResp = 0; };
		return UserResp;
	}

};
