#pragma once
#ifndef helpingfunctions_h
#define helpingfunctions_h
bool checkcnic(char* arr) {
	int k = 0;
	bool flag = true;
	while (arr[k]!='\0') {
		k++;
	}
	k++;
	if (k < 13) {
		flag=false;
	}

	for (int i = 0; i < 13; i++) {
		if (arr[i] >= '0' && arr[i] <= '9'){
			flag=true;
		}
		else {
			flag = false;
		}
	}
	return flag;
}

bool checkpassword(char* arr) {
	bool flag = false;
	bool flag1 = false;
	int k = 0;
	while (arr[k] != '\0') {
		k++;
	}
	k++;
	if (k < 9) {
		return false;
	}
	for (int i = 0; i < k; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			flag = true;
		}
		if (arr[i] >= '0' && arr[i] <= '9') {
			flag1=true;
		}
	}
	if (flag && flag1) {
		return true;
	}
	else {
		return false;
	}
	
}

bool checkname(char* arr) {
	bool flag = false;
	for (int i = 0; i < 50; i++) {
		if (arr[i] == '\0') {
			return flag;
		}
		else if (arr[i] >= '0' && arr[i] <= '9') {
			flag = false;
			return flag;
		}
		else if(arr[i] >= 'A' && arr[i] <= 'Z'){
			flag = true;
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z') {
			flag = true;
		}
	}
	return flag;
}

int str_length_return(char* arr) {
	int size = 0;
	while (arr[size] != '\0') {
		size++;
	}
	++size;
	return size;
}

bool passwordmatcher(char* arr1,char* arr2) {
	bool flag = true;
	if (str_length_return(arr1) == str_length_return(arr2)) {
		flag = true;
	}
	else {
		flag = false;
		return flag;
	}
	for (int i = 0; i < str_length_return(arr1); i++) {
		if (arr1[i] == arr2[i]) {
			flag = true;
		}
		else {
			flag = false;
			return flag;
		}
	}
	return flag;
}
#endif