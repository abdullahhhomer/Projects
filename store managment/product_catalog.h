#pragma once

#include"Headerfiles.h"
class product {
public:
	static char** prod;
	static double* price;
	static int total_elements;
	product() {
		if (price != nullptr || prod!=nullptr) {
			return;
		}
		prod = new char* [30];
		for (int i = 0; i < 30; i++) {
			prod[i] = new char[30];
		}
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				prod[i][j] = ' ';
			}
		}
		price = new double[30];
		for (int i = 0; i < 30; i++) {
			price[i] = -1;
		}
		data_saving_in_Static_arrays();
	}
	void data_saving_in_Static_arrays() {
		strcpy(prod[0], "PM01 BEEF\0");
		strcpy(prod[1], "PM02 CHICKEN\0");
		strcpy(prod[2], "PM03 MUTTON\0");
		strcpy(prod[3], "PM04 FISH\0");
		strcpy(prod[4], "PD05 MILK\0");
		strcpy(prod[5], "PD06 YOUGURT\0");
		strcpy(prod[6], "PD07 CHEESE\0");
		strcpy(prod[7], "PD08 EGGS\0");
		strcpy(prod[8], "PF09 APPLE\0");
		strcpy(prod[9], "PF10 BANANA\0");
		strcpy(prod[10],"PF11 MANGO\0");
		strcpy(prod[11],"PF12 ORANGE\0");
		strcpy(prod[12],"PF13 WATERMELON\0");
		strcpy(prod[13],"PV14 TOMATO\0");
		strcpy(prod[14],"PV15 ONION\0");
		strcpy(prod[15],"PV16 POTATOES\0");
		strcpy(prod[16],"PV17 CUCUMBER\0");
		strcpy(prod[17],"NS18 CHOCOLATES\0");
		strcpy(prod[18],"NS19 CHIPS\0");
		strcpy(prod[19],"NS20 BISCUITS\0");
		strcpy(prod[20],"NI21 LENTILS\0");
		strcpy(prod[21],"NI22 WHEAT\0");
		strcpy(prod[22],"NI23 FLOUR\0");
		strcpy(prod[23],"NI24 RICE\0");
		strcpy(prod[24],"NI25 WHEAT\0");
		strcpy(prod[25],"NP26 SHAMPOO\0");
		strcpy(prod[26],"NP27 SOAP\0");
		strcpy(prod[27],"NC28 DETERGENT\0");
		strcpy(prod[28],"NP29 DISHSOAP\0");
		strcpy(prod[29],"NP30 CLEANER\0");
		srand(time(0));
		for (int i = 0; i < 30; i++) {
			price[i] = (rand() % 300) + 240;
		}
	}
	

	
	void display_catalog() {
		bool flag = true;
		cout << "\nProduct catalog: " << endl;
		cout << "Elements\t\t" << "Price" << endl;
		for (int i = 0; i < total_elements; i++) {
			for (int j = 0; j < 30 && flag; j++) {
				if (prod[i][j] == '\0') {
					flag = false;
				}
				else if(prod[i][j]!='\0') {
					cout << prod[i][j];
				}
			}
			cout << "\t\t" << price[i];
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			flag = true;
		}
	}

	bool add() {
		char arr[30];
		double p;
		cout << "\nEnter the item you want to add (CAUTION! Follow the Serial numbers and add null!): ";
		cin.ignore();
		cin.get(arr, 30);
		cout << "\nEnter price: ";
		cin >> p;
		char** temp;
		int size = (total_elements + 1);
		temp = new char* [size];
		for (int i = 0; i < size; i++) {
			temp[i] = new char[30];
		}
		for (int i = 0; i < size-1; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (prod[i][j] == '\0') {
					temp[i][j] = prod[i][j];
					flag = false;
				}
				else if (prod[i][j] != '\0') {
					temp[i][j] = prod[i][j];
				}
				

			}
			
		}
		temp[total_elements] = arr;
		for (int i = 0; i < total_elements; i++) {
			delete[] prod[i];
		}
		delete[] prod;
		total_elements += 1;
		prod = new char* [total_elements];
		for (int i = 0; i < total_elements; i++) {
			prod[i] = new char[30];
		}
		
		for (int i = 0; i < size; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (temp[i][j] == '\0') {
					prod[i][j] = temp[i][j];
					flag = false;
				}
				else if (temp[i][j] != '\0') {
					prod[i][j] = temp[i][j];
				}
				
			}
		}
		double* ptr = new double[size];
		for (int i = 0; i < size - 1; i++){
			ptr[i] = price[i];
		}
		delete[] price;
		price = new double[total_elements];
		for (int i = 0; i < size - 1; i++) {
			price[i] = ptr[i];
		}
		
		price[size-1] =p;
		return true;
	}

	bool update() {
		int num;
		double p;
		cout << "\nEnter the numeric part of the serial number for updation: ";
		cin >> num;
		if (num > total_elements) {
			cout << "\nWrong serial number";
			Sleep(5000);
			return false;
		}
		char arr[30];
		cout << "\nEnter the element which will be used for updataion (CAUTION! ADD SERIAL NUMBER): ";
		cin.ignore();
		cin.get(arr, 30);
		cout << "\nEnter price: ";
		cin >> p;
		prod[num - 1] = arr;
		price[num - 1] = p;
		return true;
	}

	bool remove() {
		int num;
		double p = 0;
		cout << "\nEnter the numeric part of the serial number for removal: ";
		cin >> num;
		if (num > total_elements) {
			cout << "\nWrong serial number";
			Sleep(5000);
			return false;
		}
		char arr[30] = "NOT AVAILABLE";
		prod[num - 1] = arr;
		price[num - 1] = 0;
		return true;
	}


}; 
char** product::prod = nullptr;
double* product::price = nullptr;
int product::total_elements = 30;