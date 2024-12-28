#pragma once
#include"Headerfiles.h"
#include"inventory.h"
class online {
	double price;
	inventory* i;
	static char** data;
	static int* quantity;
	static int items;
	
public:
	online(int num) {
		price = 0;
		i = nullptr;
		i = new inventory(num);
	}	
		
	bool addtocart(){
		int num = 0,q=0;
		double* ptr = i->getprice();
		int* arr = i->getquantity();
		char** da = i->getdata();

		cout<<"\nEnter the serial number: ";
		cin >> num;
		cout << "\nEnter the Quantity: ";
		cin >> q;
		if (arr[num - 1] >= q) {
			price+=ptr[num - 1]*q;
			items+= 1;
			arr[num - 1] -= q;
		}
		else{
			cout << "\nYou cannnot proceed";
			return false;
		}
		
		update_cart(da[num-1],q);
		return true;
	}	

	void display_cart() {
		cout << "\nELEMENTS\t\t\tQUANTITY";
		cout << "\n-----------------------------------------------------------\n";
		for (int i = 0; i < items; i++) {
			bool flag = true;

			for (int j = 0; j < 30 && flag; j++) {
				if (data[i][j] != '\0') {
					cout << data[i][j];
				}
				else {
					flag = false;
				}
			}
			cout << "\t\t\t" << quantity[i];
			cout << "\n--------------------------------------------------------\n";
		}
	}
	void update_cart(char* arr,int q) {
		if (data == nullptr) {
			data = new char* [1];
			data[0] = new char[30];
			data[0] = arr;
			quantity = new int[1];
			quantity[0] = q;
		}
		else {
			char** products=new char*[items];
			for (int i = 0; i < items; i++) {
				products[i] = new char[30];
			}
			for (int i = 0; i < items - 1; i++) {
				bool flag = true;
				for (int j = 0; j < 30&& flag ; j++) {
					if (data[i][j] == '\0') {
						products[i][j] = data[i][j];
						flag = false;
					}
					else {
						products[i][j] = data[i][j];
					}
				}
			}
			products[items - 1] = arr;
			for (int i = 0; i < items - 1; i++) {
				delete[] data[i];
			}
			delete[] data;
			
			
			data = new char* [items];
			for (int i = 0; i < items; i++) {
				data[i] = new char[30];
			}
			
			for (int i = 0; i < items ; i++) {
				bool flag = true;
				for (int j = 0; j < 30 && flag; j++) {
					if (products[i][j] == '\0') {
						data[i][j]= products[i][j] ;
						flag = false;
					}
					else {
						data[i][j] =products[i][j] ;
					}
				}
			}

			int* qua = new int[items];
			for (int i = 0; i < items - 1; i++) {
				qua[i] = quantity[i];
			}
			qua[items - 1] = q;
			delete[] quantity;
			quantity = new int[items];
			for (int i = 0; i < items; i++) {
				quantity[i] = qua[i];
			}

		}
	}

		
	void display_inventory() {
		i->display();
	}	
	
	double getprice() {
		return price;
	}


};	
char** online::data = nullptr;
int online::items = 0;
int* online::quantity = nullptr;