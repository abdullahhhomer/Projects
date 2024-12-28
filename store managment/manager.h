#pragma once
#include"store.h"

class manager: public user {
private:
	char location[15];
	char password[16];
public:
	static int total_managers;
	store* s;
	manager(int num):user() {
		location[0] = ' ';
		password[0] = ' ';
		s = new store(num);
		string a;
		switch (num) {
		case 1:
			a = "Karachi\0";
			strcpy(location, a.c_str());
			
			break;
		case 2:
			a = "Islamabad\0";
			strcpy(location, a.c_str());
			
			break;
		case 3:
			a = "Lahore\0";
			strcpy(location, a.c_str());
			
			break;
		}

		total_managers++;
	}
	void setlocation(char* arr) {
		for (int i = 0; i < 15; i++) {
			if (arr[i] == '\0') {
				location[i] = arr[i];
				return;
			}
			else {
				location[i] = arr[i];
			}
		}
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
	char* getpassword() {
		return password;
	}
	


	char* getlocation() {
		return location;
	}

	int getmanagers() {
		return total_managers;;
	}
};
int manager::total_managers = 0;