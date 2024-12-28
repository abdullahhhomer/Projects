#pragma once
#include"Headerfiles.h"
#include"helpingfunctions.h"
#include"customer.h"
#include"admin.h"
#include"manager.h"


//customer modules
void customermenu(customer& temp);
double shopping(customer& temp);
void checkout(customer& temp);
void banktransfer(customer& temp);
void e_transaction(customer& temp);


//manager modules
void managermenu(manager& man);
void items(manager& man);

//admin modules
void adminmenu(admin& min);




void admin_login();
void manager_login();
void customer_login();
class abdullah_grocery_store {
		
public:	
	static manager* man;
	static admin* ad;
	static customer* cus;

	void registeration();
	void login();
	friend void admin_login();
	friend void customer_login();
	friend void manager_login();

};		
manager* abdullah_grocery_store::man = nullptr;
admin* abdullah_grocery_store::ad = nullptr;
customer* abdullah_grocery_store::cus = nullptr;


void abdullah_grocery_store::registeration() {
	char arr[100];
	int num;
	bool flag = true;
	
	do {
		cout << "\nChoose your location: ";
		cout << "\n1-Karachi";
		cout << "\n2-Islamabad";
		cout << "\n3-Lahore";
		cin >> num;
		if (num > 3) {
			cout << "\nWrong input!\nTry again!\n";
			flag = false;
		}
	} while (!flag);
	cus = new customer(num);
	char arr1[16];
	string s;
	switch (num) {
	case 1:
		s = "Karachi\0";
		strcpy(arr1, s.c_str());
		cus->setlocation(arr1);
		break;
	case 2:
		s = "Islamabad\0";
		strcpy(arr1, s.c_str());
		cus->setlocation(arr1);
		break;
	case 3:
		s = "Lahore\0";
		strcpy(arr1, s.c_str());
		cus->setlocation(arr1);
		break;
	}

	do {
		cin.ignore();
		cout << "\nEnter your name: ";
		
		cin.get(arr, 50);
		flag = checkname(arr);
		if (!flag) {
			cout << "\nWrong credentials";
			cout << "\nIt should not have special characters or numbers!";
		}
	}while(!flag);
	flag = true;
	cus->setname(arr);
	do {
		cout << "\nEnter your CNIC: ";
		cin.get(arr, 14);
		flag = checkcnic(arr);
		if (!flag) {
			cout << "\nWrong credentials try again!";
			continue;
		}

	} while (!flag);
	cus->setCNIC(arr);
	cin.ignore();
	flag = true;


	bool flag1 = false;
	do{
		cin.ignore();
		cout << "\nEnter your password: ";
		cin.get(arr,16);
		flag = checkpassword(arr);
		if (!flag) {
			cout << "\nIt should have atleast one upper case and One numeric letter";
			continue;
		}
		cin.ignore();
		cout << "\nEnter your password again: ";
		cin.get(arr1, 16);
		flag1 = passwordmatcher(arr, arr1);
		if (!flag1) {
			cout << "\nPasswords don't match!";
			cout << "\nTry again!";
		}
	} while (!flag &&!flag1);
	cin.ignore();
	cus->setpassword(arr);
	cout << "\nEnter your gender: ";
	cin.get(arr, 15);
	cin.ignore();
	cus->setgender(arr);
	cout << "\nEnter your address: ";
	cin.get(arr, 100);
	cus->setaddress(arr);

	fstream obj1( "customer.bin" , ios::out | ios::app | ios::binary );
	if (obj1.is_open()) {
		obj1.write((char*)&*cus, sizeof(*cus));
		cout << "\nYou are succesfuly registered";
	}
	else {
		cout << "\nError while opening file";
	}
	obj1.close();

}



void abdullah_grocery_store::login() {
	int num;
	cout << "\nChoose from the bellow options: ";
	cout << "\n1-Admin";
	cout << "\n2-Customer";
	cout << "\n3-Manager";
	cout << "\nOption!";
	cin >> num;
	switch (num) {
	case 1:
		admin_login();
		break;
	case 2:
		customer_login();
		break;
	case 3:
		manager_login();
		break;
	}
			
}		
		


void admin_login() {
	int num = 0;
	abdullah_grocery_store::ad = new admin;
	char* arr,*arr2,arr1[10];
	arr=abdullah_grocery_store::ad->getpassword();
	arr2 = abdullah_grocery_store::ad->getname();
	bool flag = false;
	do {
		cin.ignore();
		cout << "\nEnter your ID: ";
		cin.get(arr1, 10);
		flag=passwordmatcher(arr1, arr2);
		if (!flag) {
			cout << "\nYou entered the wrong ID, Try again!";
			cout << "\nYou have only three attempts if you fail the program will end";
			num++;
			continue;
			if (num == 3) {
				exit(0);
			}
		}
		num = 0;
		cin.ignore();
		cout << "\nEnter your password: ";
		cin.get(arr1, 10);
		flag = passwordmatcher(arr1, arr);
		if (!flag) {
			cout << "\nYou entered the wrong Password, Try again!";
			cout << "\nYou have only three attempts if you fail the program will end";
			num++;
			continue;
			if (num == 3) {
				exit(0);
			}
		}


	} while (!flag);
	if (flag == true) {
		cout << "\nPlease wait! ";
		Sleep(5000);
		cout << "\nLogin was successful!";

	}
	adminmenu(*abdullah_grocery_store::ad);
	



}

void manager_login() {
	int num;
	bool flag = true;
	do {
		cout << "\nChoose your location: ";
		cout << "\n1-Karachi";
		cout << "\n2-Islamabad";
		cout << "\n3-Lahore";
		cout << "\nOption: ";
		cin >> num;
		if (num > 3) {
			cout << "\nWrong input!\nTry again!\n";
			flag = false;
		}
	} while (!flag);
	char name[50];
	char password[16];
	bool flag1;
	cin.ignore();
	cout << "\nEnter your name: ";
	cin.get(name, 50);
	cin.ignore();
	cout << "\nEnter your password: ";
	cin.get(password, 16);
	static manager t(num);
	bool f1=true;
	bool f2=true;
	fstream object("manager.bin", ios::in | ios::beg | ios::binary);
	if (object.is_open()) {
		while (object.read((char*)&t, sizeof(t))) {
			f1 = passwordmatcher(name, t.getname());
			f2 = passwordmatcher(password, t.getpassword());
			if (f1 && f2) {
				cout << "\nSuccesfully login!";

			}
		}
	}
	if (f1 == false || f2 == false) {
		int num = 0;
		cout << "\nLogin failed!";
		cout << "\nDo you want to try again? (1/0)";
		cin >> num;
		if (num == 1) {
			manager_login();
		}
		else if (num == 0) {
			cout << "\nThank you for using Abdullah grocery store!";
			exit(0);
		}

	}



}

void customer_login() {
	int num;
	bool flag = true;
	do {
		cout << "\nChoose your location: ";
		cout << "\n1-Karachi";
		cout << "\n2-Islamabad";
		cout << "\n3-Lahore";
		cout << "\nOption: ";
		cin >> num;
		if (num > 3) {
			cout << "\nWrong input!\nTry again!\n";
			flag = false;
		}
	} while (!flag);
	char name[50];
	char password[16];
	bool flag1{};
	
	cout << "\nEnter your name: ";
	cin.ignore();
	cin.get(name, 50);
	
	cout << "\nEnter your password: ";
	cin.ignore();
	cin.get(password, 16);
	
	customer temp(num);
	fstream obj("customer.bin", ios::in | ios::beg | ios::binary);
	if (obj.is_open()) {
		while (obj.read((char*)&temp, sizeof(temp))) {
			flag=passwordmatcher(temp.getname(), name);
			flag1 = passwordmatcher(temp.getpassword(), password);
			if (flag1 && flag) {
				cout << "\nPlease wait! ";
				Sleep(5000);
				cout << "\nLogin was succesful";
				break;
			}
		}
	}
	else {
		cout << "\nFile did not open";
	}
	obj.close();
	if (flag == false || flag1 == false) {
		int num=0;
		cout << "\nLogin failed!";
		cout << "\nDo you want to try again? (1/0)";
		cin >> num;
		if (num == 1) {
			customer_login();
		}
		else if (num == 0) {
			cout << "\nThank you for using Abdullah grocery store!";
			exit(0);
		}

	}

	customermenu(temp);




}



void customermenu(customer& obj) {
	system("cls");
	int num=0;
	char ch;
	
	cout<<"Choose the following options: ";
	cout << "\n1-Online Shopping";
	cout << "\n2-Show inventory";
	cout << "\n3-Logout";
	cout << "\nOption: ";
	cin >> num;
	switch (num) {
	case 1:
		obj.pay->setbillamount(shopping(obj));
		checkout(obj);
		break;
	case 2:
		obj.shop->display_inventory();
		cin.ignore();
		cout << "\nDo you want to buy something? (Y/N): ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y') {
			obj.pay->setbillamount(shopping(obj));
			checkout(obj);
		}
		else {
			customermenu(obj);
		}
	case 3:
		exit(0);
		break;
	}

}


double shopping(customer& temp) {
	char ch='y';
	bool flag;
	do {
		temp.shop->display_cart();
		cout << "\n\n";
		flag=temp.shop->addtocart();
		if (!flag) {
			cout << "\nItem has insufficent quantity ";
		}
		cout << "\nDo you want to add any other items? (Y/N)";
		cin.ignore();
		ch = getche();
	} while (ch == 'y' || ch == 'Y');
	return temp.shop->getprice();
}



void checkout(customer& temp) {
	int num = 0;
	cashondelivery obj(temp.getaddress(),temp.shop->getprice());

	cout << "\nChoose any method of shopping";
	cout << "\n1-Bank transfer";
	cout << "\n2-E-Transaction";
	cout << "\n3-Cash on delivery";
	cin >> num;
	switch (num) {
	case 1:
		banktransfer(temp);
		customermenu(temp);
		break;
	case 2:
		e_transaction(temp);
		customermenu(temp);
	case 3:
		obj.transaction();
		customermenu(temp);
		break;
	}
}


void banktransfer(customer& obj) {
	int num;
	cout << "\nChoose the following options: ";
	cout << "\n1-Credit card";
	cout << "\n2-Debit card";
	cout << "\nOption: ";
	cin >> num;
	if (num == 1) {
		debit obj1(obj.pay->getbillamount());
		obj1.transaction();
	}
	else {
		credit obj1(obj.pay->getbillamount());
		obj1.transaction();
	}

}
void e_transaction(customer& obj) {
	int num;
	cout << "\nChoose the following options: ";
	cout << "\n1-Easy paisa";
	cout << "\n2-Jazz cash";
	cout << "\nOption: ";
	cin >> num;
	if (num == 1) {
		jazzcash obj1;
		obj1.setbillamount(obj.pay->getbillamount());
		obj1.transaction();
	}
	else {
		easypaisa obj1;
		obj1.setbillamount(obj.pay->getbillamount());
		obj1.transaction();
	}
	
}





void managermenu(manager& man) {
	int num;
	cout << "\nChoose the following options: ";
	cout << "\n1-Show inventory of your own store";
	cout << "\n2-Edit inventory";
	cout << "\n3-View inventory of other cities";
	cin >> num;
	switch(num) {
	case 1:
		man.s->in->display();
		cout << "\n press 1 for previous menu";
		cin >> num;
		if (num==1) {
			managermenu(man);
		}
		else {
			cout << "\nPress any key to exit: ";
			cin.ignore();
			cin.get();
			exit(0);

		}
	case 2:
		items(man);
		break;
	case 3:
		system("cls");
		cout << "\nChoose a store"; 
		cout << "\n1-Karachi";
		cout << "\n2-Islamabad";
		cout << "\n3-Lahore";
		cin >> num;
		man.s->in->display(num);
		
	}
	cout << "\n\nTo logout press 0 and for previous menu press 1";
	cin >> num;
	if (num == 0) {
		exit(0);
	}
	else {
		managermenu(man);
	}
}

void items(manager& man) {
	int num;
	cout << "\nChoose any of the options";
	cout << "\n1-Add items";
	cout << "\n2-Edit items";
	cout << "\n3-Remove items";
	cout << "\n4-Previous menu";

	cout << "\nChoice: ";
	cin >> num;
	bool flag;
	if (num == 1) {
		while (true) {
			flag = man.s->in->add();
			cout << "\nDo you want to add more items?(1/0): ";
			cin >> num;
			if (num == 1) {
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		items(man);
	}
	else if (num == 2) {
		while (true) {
			flag = man.s->in->update();
			cout << "\nDo you want to uppdate more items?(1/0): ";
			cin >> num;
			if (num == 1) {
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		items(man);
	}
	else if (num == 3) {
		while (true) {
			flag = man.s->in->remove();
			cout << "\nDo you want to remove more items?(1/0): ";
			cin >> num;
			if (num == 1) {
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		items(man);
	}
	else if (num == 4) {
		managermenu(man);
	}
	else {
		cout << "\nWrong choice choose again!";
		Sleep(3000);
		items(man);
	}
}

void adminmenu(admin& ad) {
	int num;
	cout << "\nChoose from the following options";
	cout << "\n1-Add items ";
	cout << "\n2-Update items";
	cout << "\n3-Remove items ";
	cout << "\n4-Logout";
	cout << "\nOption: ";
	cin >> num;
	if (num == 1) {
		while (true) {
			ad.obj.add();
			cout << "\nDo you want to add more items?(1/0): ";
			cin >> num;
			if (num == 1) {
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		adminmenu(ad);

	}
	else if (num == 2) {
		while (true) {
			ad.obj.update();
			cout << "\nDo you want to update more items?(1/0): ";
			cin >> num;
			if (num == 1) {
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		adminmenu(ad);
	}
	else if (num == 3) {
		while (true) {
			ad.obj.remove();
			cout << "\nDo you want to remove more items?(1/0): ";
			cin >> num;
			if (num == 1) {
				system("cls");
				continue;
			}
			else {
				break;
			}
		}
		adminmenu(ad);
	}
	else if(num==4){
		exit(0);
	}
	else {
		cout << "\nWrong input!";
		Sleep(3000);
		system("cls");
		adminmenu(ad);
	}
}