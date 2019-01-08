#pragma once
#include <iostream>

using namespace std;

class UserCommunication {
public:
	string Choice = "Error";
	string Choice_6 = "6 - Исходное Изображение";
	string Choice_1 = "1 - Сглаживание";
	string Choice_2 = "2 - Поиск Градиентов";
	string Choice_3 = "3 - Подавление не максимумов";
	string Choice_4 = "4 - Двойная пороговая фильтрация";
	string Choice_5 = "5 - Поиск границ";
	short unsigned UserResp = 0;

	void ShowMenu() {
		cout << "Выберете этап для отображения :" << endl
			
			<< Choice_1 << endl
			<< Choice_2 << endl
			<< Choice_3 << endl
			<< Choice_4 << endl
			<< Choice_5 << endl
			<< Choice_6 << endl
			<< "Сделайте выбор: ";
	}
	short unsigned UserResponse() {
		cin >> UserResp;
		if (UserResp > 6 | UserResp < 0) { return UserResp = 0; };
		return UserResp;
	}

};
