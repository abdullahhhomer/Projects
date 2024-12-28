#pragma once
#include"Abdullah_grocery_store.h"
#include"Headerfiles.h"

void module_1_() {
	system("cls");
	abdullah_grocery_store obj;
    static	int count = 0;
	int num;
	if (count == 4) {
		cout << "\nYou have had sufficent try's! try again later!";
		exit(0);
	}
	for (int i = 0; i < 100; i++) {
		cout << "*";
	}
	cout << "\n\n\t\tWelcome to Abdullah Grocery store!";
	cout << "\n\nChoose your desired option: ";
	cout << "\n1-Registeration (Only for customers)";
	cout << "\n2-Login ";
	cout << "\n3-exit";
	cout << "\nOption: ";
	cin >> num;
	switch (num) {
	case 1:
		obj.registeration();
		break;
	case 2:
		obj.login();
		break;
	case 3:
		cout << "\nWrong choice made!";
		cout << "\nTry again";
		module_1_();
		break;
	case 4:
		exit(0);
	}
}