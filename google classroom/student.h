#pragma once

#include"user.h"
#include"submission.h"
class student :public user {
	char address[100], gender[15], password[16];
	int totalclasses;
	


public:
	submission sub;
	int cla[5];
	student() :user() {
		address[0] = ' ';
		gender[0] = ' ';
		password[0] = ' ';
		totalclasses = 0;
		cla[0] = 0;
		cla[1] = 0;
		cla[2] = 0;
		cla[3] = 0;
		cla[4] = 0;


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

	void setcla(int* id) {
		for (int i = 0; i < 5; i++) {
			this->cla[i] = id[i];
		}
	}

	void display() {
		user::display();
		string add(address);
		cout << "\nAddress: " << add;
		string gen(gender);
		cout << "\nGender: " << gen;
		
	}


	char* getaddress() {
		return address;
	}

	

	char* getpassword() {
		return password;
	}

	char* getgender() {
		return gender;
	}

	bool operator==(student& obj) {
		string s1(this->getname()), s2(obj.getname());
		if (s1 == s2) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator=(int i) {
		
	}


	void operator=( student& obj) {
		this->setname(obj.getname());
		this->setaddress(obj.getaddress());
		this->setCNIC(obj.getcnic());
		this->setgender(obj.getgender());
		this->setpassword(obj.getpassword());
		this->setcla(obj.cla);
		this->sub = obj.sub;
	}

};