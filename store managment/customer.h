#pragma once
#include"Headerfiles.h"
#include"user.h"
#include"online_shopping.h"
#include"payment.h"
class customer:public user {
	char address[100],gender[15],location[20],password[16];
public:

	online* shop;
	
	payment* pay;
	
	customer(int num):user() {
		address[0] = ' ';
		location[0] = ' ';
		gender[0] = ' ';
		password[0] = ' ';
		shop = new online(num);
		pay = new payment;
	}

	void setpassword(char* arr) {
		for (int i = 0; i < 50; i++) {
			if (arr[i] == '\0') {
				password[i] = arr[i];
				return;
			}
			else
				password[i] = arr[i];
		}
	}

	void setaddress(char* arr) {
		for (int i = 0; i < 100; i++) {
			if (arr[i] == '\0') {
				address[i] = arr[i];
				return;
			}
			else {
				address[i] = arr[i];
			}
		}
	}

	void setlocation(char* arr) {
		for (int i = 0; i < 20; i++) {
			if (arr[i] == '\0') {
				location[i] = arr[i];
				return;
			}
			else {
				location[i] = arr[i];
			}
		}
	}

	void setgender(char* arr) {
		for (int i = 0; i < 15; i++) {
			if (arr[i] == '\0') {
				gender[i] = arr[i];
				return;
			}
			else {
				gender[i] = arr[i];
			}
		}
	}

	void display() {
		user::display();
		string add(address);
		cout << "\nAddress: " << add;
		string gen(gender);
		cout << "\nGender: " << gen;
		string loc(location);
		cout << "\nLocation: " << loc;
	}


	char* getaddress() {
		return address;
	}

	char* getlocation() {
		return location;
	}
	
	char* getpassword() {
		return password;
	}

	char* getgender() {
		return gender;
	}
};