#pragma once
#include"Headerfiles.h"

class user {
	char CNIC[14],name[50];
public:
	user() {
		CNIC[0] = '3';
		name[0] = 'A';
		
	}

	user(user& obj) {
		CNIC[0] = '3';
		name[0] = 'A';
		
		setname(obj.getname());
		
		setCNIC(obj.getcnic());
	}

	void setCNIC(char* arr) {
		for (int i = 0; i < 14; i++) {
				CNIC[i] = arr[i];
		}
	}
	void setname(char* arr) {
		for (int i = 0; i < 50; i++) {
			if (arr[i] == '\0') {
				name[i] = arr[i];
				return;
			}
			else {
				name[i] = arr[i];
			}
		}
	}

	
	virtual void display() {
		string cnic(CNIC);
		string na(name);
		cout << "\nName: " << na;
		cout << "\nCNIC: " << cnic;

	};

	char* getname() {
		return name;
	}

	char* getcnic() {
		return CNIC;
	}

	
};