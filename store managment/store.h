#pragma once
#include"Headerfiles.h"
#include"inventory.h"
#include<fstream>
class store {
	
	static int total_stores;
	static double revenue;
	int n;
public:
	inventory* in;
	store(int num) {
		in = new inventory(num);
		revenue = 0;
		n = num;
	}
	void write_to_file() {
		string file;
		switch (n) {
		case 1:
			file = "Lahore.bin";
			break;
		case 2:
			file = "Karachi.bin";
			break;
		case 3:
			file = "Islamabad.bin";
			break;
		}
		ofstream obj(file, ios::out | ios::app | ios::binary);
		if (obj.is_open()) {
			obj.write((char*)this, sizeof(*this));
		}
		else {
			cout << "\nFile does not exist!";

		}
		obj.close();
	}

	void read_from_file() {
		string file;
		switch (n) {
		case 1:
			file = "Lahore.bin";
			break;
		case 2:
			file = "Karachi.bin";
			break;
		case 3:
			file = "Islamabad.bin";
			break;
		}
		store temp(n);
		ifstream obj(file, ios::in| ios::beg| ios::binary);
		if (obj.is_open()) {
			obj.read((char*)&temp, sizeof(temp));
		}

		obj.close();
		temp.in->display();

	}
	static void setrevenue(double p) {
		revenue += p;
	}


}; 
int store::total_stores = 0;
double store::revenue = 0;