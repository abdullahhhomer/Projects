#pragma once 

#include"Headerfiles.h"
//class used to make online payment and it is a parent class
//it will have three child classes 


class payment { 
private:
	double bill_amount;
public:
	payment(double bill=0) {
		if (bill_amount < 0) {
			bill_amount = 0;
		}
		else {
			bill_amount = bill;
		}
	}


	//setters and getters for PAYMENT
	void setbillamount(double am) { bill_amount = am; }
	double getbillamount() { return bill_amount; }
};

class bank_transfer : public payment {
	char account_number[18];
	char name[15];
	
public:

	//1st paramterized constructor
	bank_transfer(double bill):payment(bill) {
		account_number[0] = ' ';
		name[0] = ' ';
	}
	//2nd paramterized constructor
	bank_transfer(char* acc, char* na ,double bill = 0) :payment(bill){
		account_number[0] = ' ';
		name[0] = ' ';
		for (int i = 0; i < 18; i++) {
			if (acc[i] >= '0' && acc[i] <= '9') {
				this->account_number[i] = acc[i];
			}
			else {
				cout << "\nAccount number cannot have any alphabet or special character!";
				return;
			}
		}
		for (int i = 0; i < 15; i++) {
			if (na[i] != '\0') {
				name[i] = na[i];
			}
			else {
				return;
			}
		}
	}
	//setter for bank transfer class
	void setaccount_number(char* acc) {
		for (int i = 0; i < 18; i++) {
			if (acc[i] >= '0' && acc[i] <= '9') {
				this->account_number[i] = acc[i];
			}
			else {
				cout << "\nAccount number cannot have any alphabet or special character!";
				return;
			}
		}
	}
	//getters for bank_transfer class
	void setname(char* na) {
		for (int i = 0; i < 15; i++) {
			if (na[i] != '\0') {
				name[i] = na[i];
			}
			else {
				return;
			}
		}
	}
	string getname() {
		return name;
	}
	string getaccount_number() {
		return this->account_number;
	}
	friend ifstream& operator>>(ifstream &in, bank_transfer& obj);
	friend ofstream& operator<<(ofstream &out, bank_transfer& obj);
	void input_banktransfer() {
		int num;
		cout << "\nEnter the bill amount: ";
		cin >> num;
		setbillamount(num);
		cout << "\nEnter the account number: ";
		cin.ignore();
		int i = 0;
		bool flag = true;
		while (flag) {
			for (i = 0; i < 18; i++) {
				account_number[i] = cin.get();
			}
			if (i == 18) {
				flag = false;
				break;
			}
		}
		cout << "\nEnter the name of the Account holder: ";
		cin.ignore();
		cin.get(name, 15);
	}
	void display_banktransfer() {
		
		cout << "\nName: " << getname();
		cout << "\nAccount holder: " << getaccount_number();
		cout << "\nBill Amount: " << getbillamount();
	}
};

ifstream& operator>>(ifstream &in, bank_transfer& obj) {
	int num;
	cout << "\nEnter the bill amount: ";
	cin >> num;
	obj.setbillamount(num);
	cout << "\nEnter the account number: ";
	cin.ignore();
	int i = 0;
	bool flag = true;
	while (flag) {
		for (i = 0; i < 18; i++) {
			obj.account_number[i] = cin.get();
		}
		if (i == 18) {
			flag = false;
			break;
		}
	}
	cout << "\nEnter the name of the Account holder: ";
	cin.ignore();
	cin.get(obj.name, 15);
	return in;
}

ofstream& operator<<(ofstream& out, bank_transfer& obj) {
	cout << "\nName: " << obj.getname();
	cout << "\nAccount holder: " << obj.getaccount_number();
	cout << "\nBill Amount: " << obj.getbillamount();
	return out;
}


class debit : public bank_transfer {
	char card_number[11];
	char type[12];
	double amount;
public:
	debit(double bill,double am= 10000):bank_transfer(bill),amount(am){
		card_number[0] = ' ';
		type[0] = ' ';
	}
	debit(char* cardnumber, char* ty, double am, double bill) :bank_transfer(bill),amount(am) {
		card_number[0] = ' ';
		type[0] = ' ';
		for (int i = 0; i < 11; i++) {
			if (cardnumber[i] >= '0' && cardnumber[i] <= '9') {
				this->card_number[i] = cardnumber[i];
			}
			else {
				cout << "\nCard number cannot have any alphabet or special character!";
				return;
			}
		}
		for (int i = 0; i < 12; i++) {
			if (ty[i] != '\0') {
				type[i] = ty[i];
			}
			else {
				return;
			}
		}
	}

	void setcardnumber(char* cardnumber) {
		for (int i = 0; i < 11; i++) {
			if (cardnumber[i] >= '0' && cardnumber[i] <= '9') {
				this->card_number[i] = cardnumber[i];
			}
			else {
				cout << "\nCard number cannot have any alphabet or special character!";
				return;
			}
		}
	}
	void settype(char* ty) {
		for (int i = 0; i < 12; i++) {
			if (ty[i] != '\0') {
				type[i] = ty[i];
			}
			else {
				return;
			}
		}
	}
	void setamount(double am) {
		amount = am;
	}
	string get_type() {
		return type;
	}
	string get_cardnumber() {
		return card_number;
	}
	double get_amount() {
		return amount;
	}
	void transaction() {
		if (this->getbillamount() <= amount) {
			amount -= getbillamount();
			this->setbillamount(0);
			cout << "\nTransaction is processing.....";
			Sleep(5000);
			system("cls");
			cout << "\nTransaction was successful!";
		}
		else {
			cout << "\nTransaction is processing.....";
			Sleep(5000);
			system("cls");
			cout << "\nTransaction cannot be processed you have insufficent balance!! ";
			cout << "\nAdd balance! ";
			double p;
			cout << "\nEnter amount you want to add: ";
			cin >> p;
			amount += p;
		}
	}
	friend ifstream& operator>>(ifstream& in, debit& obj);
	friend ofstream& operator<<(ofstream& in, debit& obj);
};
ifstream& operator>>(ifstream& in, debit& obj) {
	obj.input_banktransfer();
	cout << "\nEnter your card number: ";
	cin.ignore();
	int i = 0;
	bool flag = true;
	while (flag) {
			while(i < 11) {
				obj.card_number[i] = cin.get();
			if (obj.card_number[i] >= '0' && obj.card_number[i] <= '9') {
					i++;
				}
			else {
				i=0;
				cout << "\nTry again!\nCard number cannot have alphabet and special character";
				continue;

				}
			}
		if (i == 11) {
			flag = false;
			break;
		}
	}

	cout << "\nEnter card type: \n1-Visa\t2-Master\t3-Pak pay";
	cin.get(obj.type, 12);
	cout << "\nEnter the amount in your card: ";
	cin >> obj.amount;
	return in;
}


ofstream& operator<<(ofstream& in, debit& obj) {
	obj.display_banktransfer();
	cout << "\nCard number: " << obj.get_cardnumber();
	cout << "\nCard type: " << obj.get_type();
	cout << "\nBalance: " << obj.get_amount();
	return in;
}



class credit : public bank_transfer {
	char card_number[11];
	char type[12];
	double amount;
public:
	credit( double bill, double am=10000) :bank_transfer(bill), amount(am) {
		card_number[0] = ' ';
		type[0] = ' ';
	}
	credit(char* cardnumber, char* ty, double am, double bill) :bank_transfer(bill), amount(am) {
		card_number[0] = ' ';
		type[0] = ' ';
		for (int i = 0; i < 11; i++) {
			if (cardnumber[i] >= '0' && cardnumber[i] <= '9') {
				this->card_number[i] = cardnumber[i];
			}
			else {
				cout << "\nCard number cannot have any alphabet or special character!";
				return;
			}
		}
		for (int i = 0; i < 12; i++) {
			if (ty[i] != '\0') {
				type[i] = ty[i];
			}
			else {
				return;
			}
		}
	}

	void setcardnumber(char* cardnumber) {
		for (int i = 0; i < 11; i++) {
			if (cardnumber[i] >= '0' && cardnumber[i] <= '9') {
				this->card_number[i] = cardnumber[i];
			}
			else {
				cout << "\nCard number cannot have any alphabet or special character!";
				return;
			}
		}
	}
	void settype(char* ty) {
		for (int i = 0; i < 12; i++) {
			if (ty[i] != '\0') {
				type[i] = ty[i];
			}
			else {
				return;
			}
		}
	}
	void setamount(double am) {
		amount = am;
	}
	string get_type() {
		return type;
	}
	string get_cardnumber() {
		return card_number;
	}
	double get_amount() {
		return amount;
	}
	void transaction() {
		if (this->getbillamount() <= amount) {
			amount -= getbillamount();
			this->setbillamount(0);
			cout << "\nTransaction is processing.....";
			Sleep(5000);
			system("cls");
			cout << "\nTransaction was successful!";
		}
		else {
			cout << "\nTransaction is processing.....";
			Sleep(5000);
			system("cls");
			cout << "\nTransaction cannot be processed you have insufficent balance!! ";
			cout << "\nAdd balance! ";
			double p;
			cout << "\nEnter amount you want to add: ";
			cin >> p;
			amount += p;
		}
	}
	friend ifstream& operator>>(ifstream& in, credit& obj);
	friend ofstream& operator<<(ofstream& in, credit& obj);
};
ifstream& operator>>(ifstream& in, credit& obj) {
	obj.input_banktransfer();
	cout << "\nEnter your card number: ";
	cin.ignore();
	int i = 0;
	bool flag = true;
	while (flag) {
		cin.ignore();
		while (i < 11) {
			obj.card_number[i] = getche();
			if (obj.card_number[i] >= '0' && obj.card_number[i] <= '9') {
				i++;
			}
			else {
				i = 0;
				cout << "\nTry again!\nCard number cannot have alphabet and special character";
				cout << "\nEnter card number: ";
				continue;

			}
		}
		if (i == 11) {
			flag = false;
			break;
		}
	}

	cout << "\nEnter card type: \n1-Visa\t2-Master\t3-Pak pay";
	cin.get(obj.type, 12);
	cout << "\nEnter the amount in your card: ";
	cin >> obj.amount;
	return in;
}


ofstream& operator<<(ofstream& in, credit& obj) {
	obj.display_banktransfer();
	cout << "\nCard number: " << obj.get_cardnumber();
	cout << "\nCard type: " << obj.get_type();
	cout << "\nBalance: " << obj.get_amount();
	return in;
}



class etransaction : public payment {
	char number[11];
public:
	etransaction():payment() {
		number[0] = '0';
	}
	etransaction(char* num,int bill):payment(bill) {
		number[0] = '0';
		for (int i = 0; i < 11; i++) {
			if (num[i] >= '0' && num[i] <= '9') {
				number[i] = num[i];
			}
			else {
				cout << "\nPhone number cannot have any alphabet or special character";
			}
		}
	}
	void setnumber(char* num) {
		for (int i = 0; i < 11; i++) {
			if (num[i] >= '0' && num[i] <= '9') {
				number[i] = num[i];
			}
			else {
				cout << "\nPhone number cannot have any alphabet or special character";
			}
		}
	}
	string getnumber() {
		return number;
	}

};

class easypaisa : public etransaction {
	double amount;
	char name[15];
public:
	easypaisa() :etransaction() {
		amount = 10000;
		name[0] = '0';
	}
	easypaisa( char* na, double bill,double am = 10000,char* number=nullptr) :etransaction(number, bill) {
		amount = am;
		name[0] = '0';
		for (int i = 0; i < 15; i++) {
			if (na[i] != '\0') {
				name[i] = na[i];
			}
			else {
				return;
			}
		}

	}
	void transaction() {
		if (this->getbillamount() <= amount) {
			amount -= this->getbillamount();
			this->setbillamount(0);
		}
		else {
			cout << "\nTransaction cannot be processed you have insufficent balance!! ";
			cout << "\nAdd balance! ";
			double p;
			cout << "\nEnter amount you want to add: ";
			cin >> p;
			amount += p;
		}
	}

};

class jazzcash : public etransaction {
	double amount;
	char name[15];
public:
	jazzcash() :etransaction() {
		amount = 10000;
		name[0] = '0';
	}
	jazzcash(char* na, char* number, double bill,double am = 10000 ) :etransaction(number, bill) {
		amount = am;
		name[0] = '0';
		for (int i = 0; i < 15; i++) {
			if (na[i] != '\0') {
				name[i] = na[i];
			}
			else {
				return;
			}
		}

	}
	void transaction() {
		if (this->getbillamount() <= amount) {
			amount -= this->getbillamount();
			this->setbillamount(0);
		}
		else {
			cout << "\nTransaction cannot be processed you have insufficent balance!! ";
			cout << "\nAdd balance! ";
			double p;
			cout << "\nEnter amount you want to add: ";
			cin >> p;
			amount += p;
		}
	}

};


class cashondelivery:public payment{
	char address[50];
public:
	cashondelivery(char* add,double bill):payment(bill) {
		address[0] = ' ';
		for (int i = 0; i < 50; i++) {
			if (add[i] != '\0') {
				address[i] = add[i];
			}
			else {
				return;
			}
		}
	}
	void setaddress(char* add) {
		for (int i = 0; i < 50; i++) {
			if (add[i] != '\0') {
				address[i] = add[i];
			}
			else {
				return;
			}
		}
	}
	string getaddress() {
		return address;
	}
	void transaction() {
		cout << "\nOur rider is on the way";
		cout << "\nHe'll deliver your order in 45 minutes";
	}
};

