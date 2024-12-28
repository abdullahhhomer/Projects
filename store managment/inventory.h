#pragma once
#include"Headerfiles.h"
#include"product_catalog.h"
class inventory {
	static char** data;
	static int total_items;
	static double* price;
	static int* quantity;
	
	static char** data1;
	static int total_items1;
	static double* price1;
	static int* quantity1;

	static char** data2;
	static int total_items2;
	static double* price2;
	static int* quantity2;

	static char** data3;
	static int total_items3;
	static double* price3;
	static int* quantity3;

	int number;

	product p;

	void populate_Lahore() {
		total_items3 = p.total_elements;
		data3 = new char* [total_items3];
		for (int i = 0; i < total_items3; i++) {
			data3[i] = new char[30];
		}
		price3 = new double[total_items3];
		quantity3 = new int[total_items3];
		bool flag = true;
		for (int i = 0; i < total_items3; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (p.prod[i][j] == '\0') {
					data3[i][j] = p.prod[i][j];
					flag = false;
				}
				else if (p.prod[i][j] != '\0') {
					data3[i][j] = p.prod[i][j];
				}
			}
		}
		for (int i = 0; i < total_items3; i++) {
			price3[i] = p.price[i];
		}
		srand(time(0));
		for (int i = 0; i < total_items3; i++) {
			quantity3[i] = rand() % 50 + 50;
		}

	}

	void populate_karachi() {
		total_items1 = p.total_elements;
		data1 = new char* [total_items1];
		for (int i = 0; i < total_items1; i++) {
			data1[i] = new char[30];
		}
		price1 = new double[total_items1];
		quantity1 = new int[total_items1];
		bool flag = true;
		for (int i = 0; i < total_items1; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (p.prod[i][j] == '\0') {
					data1[i][j] = p.prod[i][j];
					flag = false;
				}
				else if (p.prod[i][j] != '\0') {
					data1[i][j] = p.prod[i][j];
				}
			}
		}
		for (int i = 0; i < total_items1; i++) {
			price1[i] = p.price[i];
		}
		srand(time(0));
		for (int i = 0; i < total_items1; i++) {
			quantity1[i] = rand() % 50 + 50;
		}
	}

	void populate_islamabad() {
		total_items2 = p.total_elements;
		data2 = new char* [total_items2];
		for (int i = 0; i < total_items2; i++) {
			data2[i] = new char[30];
		}
		price2 = new double[total_items2];
		quantity2 = new int[total_items2];
		bool flag = true;
		for (int i = 0; i < total_items2; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (p.prod[i][j] == '\0') {
					data2[i][j] = p.prod[i][j];
					flag = false;
				}
				else if (p.prod[i][j] != '\0') {
					data2[i][j] = p.prod[i][j];
				}
			}
		}
		for (int i = 0; i < total_items2; i++) {
			price2[i] = p.price[i];
		}
		srand(time(0));
		for (int i = 0; i < total_items2; i++) {
			quantity2[i] = rand() % 50 + 50;
		}
	}

public:
	inventory(int num) {
		data = nullptr;
		price = nullptr;
		quantity = nullptr;
		total_items = 0;
		number = num;
		switch (num) {
		case 1:
			populate_karachi();
			data = data1;
			price = price1;
			quantity = quantity1;
			total_items = total_items1;
			break;
		case 2:
			populate_islamabad();
			data = data2;
			price = price2;
			quantity = quantity2;
			total_items = total_items2;
			break;
		case 3:
			populate_Lahore();
			data = data3;
			price = price3;
			quantity = quantity3;
			total_items = total_items3;
			break;
		}
		if (num == 2) {
			populate_karachi();
			populate_Lahore();
		}
		else if (num == 1) {
			populate_islamabad();
			populate_Lahore();
		}
		else {
			populate_islamabad();
			populate_karachi();
		}
	}

	inventory(inventory& obj) {
		total_items = obj.gettotal_items();
		char** d = obj.getdata();
		int* q = obj.getquantity();
		double* p = obj.getprice();
		data = new char* [total_items];
		for (int i = 0; i < total_items; i++) {
			data[i] = new char[30];
		}
		quantity = new int[total_items];
		price = new double[total_items];
		for (int i = 0; i < total_items; i++) {
			bool flag = true;
			for (int j = 0; j < total_items && flag; j++) {
				if (d[i][j] == '\0') {
					data[i][j] = d[i][j];
					flag = false;
				}
				else {
					data[i][j] = d[i][j];
				}
			}
			quantity[i] = q[i];
			price[i] = p[i];
		}
	}


	bool add() {
		char arr[30];
		double p;
		int q;
		cout << "\nEnter the item you want to add (CAUTION! Follow the Serial numbers and add null!): ";
		cin.ignore();
		cin.get(arr, 30);
		cout << "\nEnter price: ";
		cin >> p;
		cout << "\nEnter Quantity: ";
		cin >> q;
		char** temp;
		int size = (total_items + 1);
		temp = new char* [size];
		for (int i = 0; i < size; i++) {
			temp[i] = new char[30];
		}
		for (int i = 0; i < size - 1; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (data[i][j] == '\0') {
					temp[i][j] = data[i][j];
					flag = false;
				}
				else if (data[i][j] != '\0') {
					temp[i][j] = data[i][j];
				}


			}

		}
		temp[total_items] = arr;
		for (int i = 0; i < total_items; i++) {
			delete[] data[i];
		}
		delete[] data;
		total_items += 1;
		data = new char* [total_items];
		for (int i = 0; i < total_items; i++) {
			data[i] = new char[30];
		}
		for (int i = 0; i < size; i++) {
			bool flag = true;
			for (int j = 0; j < 30 && flag; j++) {
				if (temp[i][j] == '\0') {
					data[i][j] = temp[i][j];
					flag = false;
				}
				else if (temp[i][j] != '\0') {
					data[i][j] = temp[i][j];
				}
			}
		}
		double* ptr = new double[size];
		for (int i = 0; i < size - 1; i++) {
			ptr[i] = price[i];
		}
		delete[] price;
		price = new double[total_items];
		for (int i = 0; i < size - 1; i++) {
			price[i] = ptr[i];
		}
		price[size - 1] = p;
		int* ptr1 = new int[size];
		for (int i = 0; i < size - 1; i++) {
			ptr1[i] = price[i];
		}
		delete[] quantity;
		quantity = new int[total_items];
		for (int i = 0; i < size - 1; i++) {
			quantity[i] = ptr1[i];
		}
		quantity[size - 1] = q;
		return true;
	}

	bool remove() {
		int num;
		double p = 0;
		cout << "\nEnter the numeric part of the serial number for removal: ";
		cin >> num;
		if (num > total_items) {
			cout << "\nWrong serial number";
			Sleep(5000);
			return false;
		}
		char arr[30] = "NOT AVAILABLE";
		data[num - 1] = arr;
		price[num - 1] = 0;
		quantity[num - 1] = 0;
		return true;
	}

	bool update() {
		int num;
		double p;
		int q = 0;
		cout << "\nEnter the numeric part of the serial number for updation: ";
		cin >> num;
		if (num > total_items) {
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
		cout << "\nEnter quantity: ";
		data[num - 1] = arr;
		price[num - 1] = p;
		quantity[num - 1] = q;
		return true;
	}

	char** getdata() {
		return data;
	}
	double* getprice() {
		return price;
	}
	int* getquantity() {
		return quantity;
	}
	int gettotal_items() {
		return total_items;
	}



	void display(int num=0) {
		if (num == 0) {
			num = number;
		}
		if (num == 1) {
			cout << "\nKarachi store\n";
			cout << "\nELEMENTS\t\t\tPRICE\t\t\tQUANTITY";
			cout << "\n-----------------------------------------------------------\n";
			for (int i = 0; i < total_items; i++) {
				bool flag = true;

				for (int j = 0; j < 30 && flag; j++) {
					if (data[i][j] != '\0') {
						cout << data[i][j];
					}
					else {
						flag = false;
					}
				}
				cout << "\t\t\t" << price[i] << "\t\t" << quantity[i];
				cout << "\n--------------------------------------------------------\n";
			}
		}
		else if (num == 2) {
			cout << "\nIslamabad store\n";
			cout << "\nELEMENTS\t\t\tPRICE\t\t\tQUANTITY";
			cout << "\n-----------------------------------------------------------\n";
			for (int i = 0; i < total_items1; i++) {
				bool flag = true;

				for (int j = 0; j < 30 && flag; j++) {
					if (data1[i][j] != '\0') {
						cout << data1[i][j];
					}
					else {
						flag = false;
					}
				}
				cout << "\t\t\t" << price1[i] << "\t\t" << quantity1[i];
				cout << "\n--------------------------------------------------------\n";
			}
		}
		else if (num == 3) {
			cout << "\nLahore store\n";
			cout << "\nELEMENTS\t\t\tPRICE\t\t\tQUANTITY";
			cout << "\n-----------------------------------------------------------\n";
			for (int i = 0; i < total_items2; i++) {
				bool flag = true;

				for (int j = 0; j < 30 && flag; j++) {
					if (data2[i][j] != '\0') {
						cout << data2[i][j];
					}
					else {
						flag = false;
					}
				}
				cout << "\t\t\t" << price2[i] << "\t\t" << quantity2[i];
				cout << "\n--------------------------------------------------------\n";
			}
		}
	}

};

char** inventory::data=nullptr;
int inventory::total_items=0;
double* inventory::price=nullptr;
int* inventory::quantity=nullptr;

char** inventory::data1 = nullptr;
int inventory::total_items1 = 0;
double* inventory::price1 = nullptr;
int* inventory::quantity1 = nullptr;

char** inventory::data2 = nullptr;
int inventory::total_items2 = 0;
double* inventory::price2 = nullptr;
int* inventory::quantity2 = nullptr;

char** inventory::data3 = nullptr;
int inventory::total_items3 = 0;
double* inventory::price3 = nullptr;
int* inventory::quantity3 = nullptr;
