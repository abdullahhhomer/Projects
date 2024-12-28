#pragma once
#include"user.h"



class teacher : public user {
private:
	char password[16];
	char subject[16];
	


public:
	
	teacher() :user() {
		password[0] = ' ';
		subject[0] = ' ';
		id = " ";
	
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

	void setsubject(char* arr) {
		for (int i = 0; i < 16; i++) {
			if (arr[i] == '\0') {
				subject[i] = arr[i];
				return;
			}
			else
				subject[i] = arr[i];
		}
	}


	char* getpassword() {
		return password;
	}

	char* getsubject() {
		return subject;
	}

	bool operator==(teacher& obj) {
		string s1(this->getname()), s2(obj.getname());
		if (s1 == s2) {
			return true;
		}

		else {
			return false;
		}
	}


	void operator=(teacher& obj) {
		this->setname(obj.getname());
		this->setCNIC(obj.getcnic());
		this->setpassword(obj.getpassword());
		this->setsubject(obj.getsubject());
	}

};