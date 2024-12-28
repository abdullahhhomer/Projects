#pragma once
#include"Headerfiles.h"
#include"manager.h"
#include"product_catalog.h"

class admin : public user{
	char name[6] = "admin";
	char password[6] = "root";
public:
	product obj;
	admin() {
		char arr[5];
		string s = "root";
		strcpy(arr, s.c_str());
		this->setpassword(arr);
	}



	void registermanager() {
		if (manager::total_managers >= 3) {
			cout << "\nMaximum numbers of managers are registerd! ";
		}	
		else {
			char cnic[13];
			cout << "\nEnter your CNIC: ";
			cin.get(cnic, 13);
			bool flag=checkcnic(cnic);
			if (!flag) {
				cout << "\nWrong credentials try again!";
				this->registermanager();
			}
			int num;
			cout << "\nChoose your location: ";
			cout << "\n1-Karachi";
			cout << "\n2-Islamabad";
			cout << "\n3-Lahore";
			cin >> num;
			manager m(num);
			m.setCNIC(cnic);
			char arr[20];
			cout << "\nEnter your name: ";
			cin.get(arr, 20);
			m.setname(arr);
			fstream obj1("manager.bin", ios::app | ios::out | ios::binary);
			if (obj1.is_open()) {
				obj1.write((char*)&m, sizeof(m));
				cout << "\nSuccessfully registered! ";
			}
			else {
				cout << "\nError!";
			}
		}


	}
	
	void setpassword(char* arr) {
		for (int i = 0; i < 50; i++) {
			if (arr[i] == '\0') {
				password[i] = arr[i];
				return;
			}
		}
	}

	char* getpassword() {
		return password;
	}

	char* getname() {
		return name;
	}
};