#pragma once

#include"Headerfiles.h"
#include"classes.h"
#include<time.h>
using namespace std;

bool checkcnic(char* arr) {
	int k = 0;
	bool flag = true;
	while (arr[k] != '\0') {
		k++;
	}
	k++;
	if (k < 13) {
		flag = false;
	}

	for (int i = 0; i < 13; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			flag = true;
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
			flag1 = true;
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
		else if (arr[i] >= 'A' && arr[i] <= 'Z') {
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

bool passwordmatcher(char* arr1, char* arr2) {
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




class googleclassroom {
public:
	teacher tea;
	student stud;
	classes* first;
	int total;
	googleclassroom() {
		total = 0;
	}
	/*void create_class(int id,string desc,string subj) {
		if (total == 0) {
			first = new classes(id);
			first->subject = subj;
			first->description = desc;
			first->teach = tea;
		}
	}*/
	void add_classes(classes& obj) {
		if (total == 0) {
			first = new classes;
			*first = obj;
			total++;
			return;
		}
		else {
			total++;
			classes* temp = new classes[total];
			for (int i = 0; i < total; i++) {
				temp[i] = first[i];
			}
			temp[total] = obj;
			first = temp;

		}
	}

	void delete_class(int id) {
		
	}




	void registeration_teacher();
	void registeration_student();
	void teacher_login();
	void student_login();
	void teacher_menu();
	void student_menu();
	int return_class_index(int id) {
		for (int i = 0; i < total; i++) {
			if (first[i].id == id) {
				return i;
			}
		}
	}

	void menu();

	void write_classes() {
		for (int i = 0; i < total; i++) {
			first[i].write_in_file();
		}
	}
	void operator=(googleclassroom& obj) {
		this->tea = obj.tea;
		this->stud = obj.stud;
		this->total = obj.total;
		for (int i = 0; i < this->total; i++) {
			this->add_classes(obj.first[i]);
		}
	}
};
//teacher googleclassroom::tea =tea;
//student googleclassroom::stud = stud;
//classes* googleclassroom::first = NULL;
//int googleclassroom::total =0;

void googleclassroom::menu() {
	int opt;
	cout << "\nChoose:";
	cout << "\n1-Register for student";
	cout << "\n2-Register for Teacher";
	cout << "\n3-login for teacher";
	cout << "\n4-login for student";
	cout << "\nOption: ";
	cin >> opt;
	switch (opt) {
	case 1:
		this->registeration_student();
		break;
	case 2:
		this->registeration_teacher();
		break;
	case 3:
		this->teacher_login();
		break;
	case 4:
		this->student_login();
		break;
	default:
		cout << "\nWrong input,try again!";
		this->menu();
	}
}




void googleclassroom::registeration_student() {
	char arr[100];
	int num;
	bool flag = true;


	char arr1[16];
	string s;

	do {
		cin.ignore();
		cout << "\nEnter your name: ";
		cin.get(arr, 50);
		
		flag = checkname(arr);
		if (!flag) {
			cout << "\nWrong credentials";
			cout << "\nIt should not have special characters or numbers!";
		}
	} while (!flag);
	flag = true;
	
	stud.setname(arr);
	do {
		cin.ignore();
		cout << "\nEnter your CNIC: ";
		cin.get(arr, 14);
		flag = checkcnic(arr);
		if (!flag) {
			cout << "\nWrong credentials try again!";
			continue;
		}

	} while (!flag);
	stud.setCNIC(arr);
	
	flag = true;


	bool flag1 = false;
	do {
		cin.ignore();
		cout << "\nEnter your password: ";
		cin.get(arr, 16);
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
	} while (!flag && !flag1);
	
	stud.setpassword(arr);
	cin.ignore();
	cout << "\nEnter your gender: ";
	cin.get(arr, 15);
	
	stud.setgender(arr);
	cin.ignore();
	cout << "\nEnter your address: ";
	cin.get(arr, 100);
	stud.setaddress(arr);
	int ids[5];
	cout << "\nEnter the subject codes you want to be enrolled in(codes start from 1-10 and there are 5 subjects for each student): ";
	for (int i = 0; i < 5; i++) {
		cin >> ids[i];
	}
	stud.setcla(ids);
	string s1(stud.getname());
	stud.id = s1;
	


	fstream obj1("student.bin", ios::out | ios::app | ios::binary);
	if (obj1.is_open()) {
		obj1.write((char*)&stud, sizeof(stud));
		cout << "\nYou are succesfuly registered";
	}
	else {
		cout << "\nError while opening file";
	}
	obj1.close();
	this->menu();
}



void googleclassroom::registeration_teacher() {
	char arr[100];
	int num;
	bool flag = true;


	char arr1[16];
	string s;

	do {
		cin.ignore();
		cout << "\nEnter your name: ";

		cin.get(arr, 50);
		flag = checkname(arr);
		if (!flag) {
			cout << "\nWrong credentials";
			cout << "\nIt should not have special characters or numbers!";
		}
	} while (!flag);
	flag = true;

	tea.setname(arr);
	do {
		cin.ignore();
		cout << "\nEnter your CNIC: ";
		cin.get(arr, 14);
		flag = checkcnic(arr);
		if (!flag) {
			cout << "\nWrong credentials try again!";
			continue;
		}

	} while (!flag);
	tea.setCNIC(arr);
	cin.ignore();
	flag = true;


	bool flag1 = false;
	do {
		cin.ignore();
		cout << "\nEnter your password: ";
		cin.get(arr, 16);
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
	} while (!flag && !flag1);

	tea.setpassword(arr);
	cin.ignore();
	cout << "\nEnter your subject: ";
	cin.get(arr, 100);
	tea.setsubject(arr);

	char* temp;
	temp = stud.getcnic();
	temp += 9;
	string s1(tea.getname());
	tea.id = s1 ;


	fstream obj1("teacher.bin", ios::out | ios::app | ios::binary);
	if (obj1.is_open()) {
		obj1.write((char*)&tea, sizeof(tea));
		cout << "\nYou are succesfuly registered";
	}
	else {
		cout << "\nError while opening file";
	}
	obj1.close();
	this->menu();
}



void googleclassroom::teacher_login() {
	char name[50];
	char password[16];
	bool flag1;
	cin.ignore();
	cout << "\nEnter your name: ";
	cin.get(name, 50);
	cin.ignore();
	cout << "\nEnter your password: ";
	cin.get(password, 16);
	
	bool f1 = true;
	bool f2 = true;
	fstream object("teacher.bin", ios::in | ios::beg | ios::binary);
	if (object.is_open()) {
		while (object.read((char*)&tea, sizeof(tea))) {
			f1 = passwordmatcher(name, tea.getname());
			f2 = passwordmatcher(password, tea.getpassword());
			if (f1 && f2) {
				cout << "\nSuccesfully login!";
			}
		}
	}
	object.close();
	if (f1 == false || f2 == false) {
		int num = 0;
		cout << "\nLogin failed!";
		cout << "\nDo you want to try again? (1/0)";
		cin >> num;
		if (num == 1) {
			teacher_login();
		}
		else if (num == 0) {
			
			exit(0);
		}

	}
	classes temp;
	fstream file("classes.bin", ios::in | ios::out | ios::binary);
	int count = 0;
	if (file.is_open()) {
		while (file.read((char*)&temp.total_students, sizeof(temp.total_students)) &&
			file.read((char*)&temp.total_assignments, sizeof(temp.total_assignments)) &&
			file.read((char*)&temp.teach, sizeof(temp.teach)) &&
			file.read((char*)&temp.id, sizeof(temp.id)) &&
			file.read((char*)&temp.description, sizeof(temp.description)) &&
			file.read((char*)&temp.subject, sizeof(temp.subject))) {
			for (int i = 0; i < temp.total_students; i++) {
				file.read((char*)&temp.s[i], sizeof(temp.s[i]));
			}
			for (int i = 0; i < temp.total_assignments; i++) {
				file.read((char*)&temp.assign[i], sizeof(temp.assign[i]));
			}
			if (temp.teach == tea) {
				this->add_classes(temp);
			}
		}
	}
	else {
		cout << "\nError in opening file";
	}



	this->teacher_menu();


}


void googleclassroom::student_login() {
	char name[50];
	char password[16];
	bool flag1;
	cin.ignore();
	cout << "\nEnter your name: ";
	cin.get(name, 50);
	cin.ignore();
	cout << "\nEnter your password: ";
	cin.get(password, 16);
	
	bool f1 = true;
	bool f2 = true;
	fstream object("student.bin", ios::in | ios::beg | ios::binary);
	if (object.is_open()) {
		while (object.read((char*)&stud, sizeof(stud))) {
			f1 = passwordmatcher(name, stud.getname());
			f2 = passwordmatcher(password, stud.getpassword());
			if (f1 && f2) {
				cout << "\nSuccesfully login!";
			}
		}
	}
	object.close();
	if (f1 == false || f2 == false) {
		int num = 0;
		cout << "\nLogin failed!";
		cout << "\nDo you want to try again? (1/0)";
		cin >> num;
		if (num == 1) {
			student_login();
		}
		else if (num == 0) {
			exit(0);
		}

	}
	classes temp;
	/*fstream file("classes.bin", ios::in | ios::out | ios::binary | ios::beg);
	int count = 0;
	bool ch = true;
	if (file.is_open()) {
		while (!file.eof()) {
			file.read((char*)&temp.total_students, sizeof(temp.total_students));
			file.read((char*)&temp.total_assignments, sizeof(temp.total_assignments));
			file.read((char*)&temp.teach, sizeof(temp.teach));
			file.read((char*)&temp.id, sizeof(temp.id));
			file.read((char*)&temp.description, sizeof(temp.description));
			file.read((char*)&temp.subject, sizeof(temp.subject));
			for (int i = 0; i < temp.total_students; i++) {
				file.read((char*)&temp.s[i], sizeof(temp.s[i]));
				if (temp.s[i] == stud) {
					this->add_classes(temp);

				}
			}
			for (int i = 0; i < temp.total_assignments; i++) {
				file.read((char*)&temp.assign[i], sizeof(temp.assign[i]));
			}
		}
	}
	file.close();*/

	fstream file("classes.bin", ios::in | ios::out | ios::binary | ios::beg);
	int count = 0;
	bool ch = true;

	if (file.is_open()) {
		file.seekg(0, ios::beg); 

		while (file.read((char*)&temp.total_students, sizeof(temp.total_students)) &&
			file.read((char*)&temp.total_assignments, sizeof(temp.total_assignments)) &&
			file.read((char*)&temp.teach, sizeof(temp.teach)) &&
			file.read((char*)&temp.id, sizeof(temp.id)) &&
			file.read((char*)&temp.description, sizeof(temp.description)) &&
			file.read((char*)&temp.subject, sizeof(temp.subject))) {

			for (int i = 0; i < temp.total_students; i++) {
				file.read((char*)&temp.s[i], sizeof(temp.s[i]));
				if (temp.s[i]== stud)  {					
					this->add_classes(temp);
				}
			}
			for (int i = 0; i < temp.total_assignments; i++) {
				file.read((char*)&temp.assign[i], sizeof(temp.assign[i]));
			}
		}
	}
	else {
		cout << "\nError in opening file";
	}



	this->student_menu();

}

void googleclassroom::teacher_menu() {
	system("cls");
	
	int opt;
	int id;
	char arr[20];
	classes* cs;
	student tem;
	bool check;
	cout << "\nTeachers menu:";
	cout << "\n1-View enrolled classes";
	cout << "\n2-Create class";
	cout << "\n3-delete class";
	cout << "\n4-Create assignment";
	cout << "\n5-delete assignment";
	cout << "\n6-assignment marks";
	cout << "\n7-Mark grades";
	cout << "\n8-Add students";
	cout << "\n9-Remove students";
	cout << "\n10-View submissions";
	cout << "\n11-Logout";
	cout << "\nOption: ";
	cin >> opt;
	if (opt == 1) {
		cout << "\nEnrolled classes are: ";
		for (int i = 0; i < total; i++) {
			first[i].display();
		}
	}
	else if (opt == 2) {
		string str;
		classes obj;
		cout << "\nEnter class ID: ";
		cin >> id;
		obj.id = id;
		cin.ignore();
		cout << "\nEnter class description: ";
		cin.get(obj.description,90);
		cin.ignore();
		cout << "\nEnter subject: ";
		cin.get(obj.subject, 90);;
		this->add_classes(obj);
		for (int i = 0; i < total; i++) {
			first[i].teach = tea;
		}
		
	}
	else if (opt == 3) {
		cout << "\nEnter class ID: ";
		cin >> id;
		this->delete_class(id);
		for (int i = 0; i < total; i++) {
			first[i].teach = tea;
		}
	}
	else if (opt == 4) {
		string title, desc, dead;
		int mar;
		cout << "\nEnter class ID: ";
		cin >> id;
	
		bool flag = true;
		
			cout << "\nEnter title: ";
			cin >> title;
			cout << "\nEnter Description: ";
			cin >> desc;
			cin.ignore();
			cout << "\nEnter total marks:";
			cin >> mar;
			assignment assign(title, desc, mar);
		do{
			cout << "\nEnter assignment deadline (YYYY-MM-DD HH:MM): ";
			cin >> dead;
			tm tm = {};
			istringstream ss(dead);
			ss >> get_time(&tm, "%Y-%m-%d %H:%M");
			if (ss.fail()) {
				cout << "\nError passing the deadline string." << endl;
				cout << "\nTry again";
				continue;
			}
			
			
			assign.tim = mktime(&tm);
			if (assign.time_check()) {
				cout << "\nWrong time entered, you have entered a previous date\nTry again!";
				continue;
			}
			flag = false;
		} while (flag);
		flag = true;
		do {
			cout << "\nEnter the index of class: ";
			cin >> id;
			if (id > total) {
				cout << "\nEntered wrong credentials";
				continue;
			}
			first[id].addassignment(assign);
			flag = false;
		} while (flag);
	}
	else if (opt == 5) {
		cout << "\nEnter assignment number: ";
		cin >> opt;
		bool flag = true;
		do {
			cout << "\nEnter the index of class: ";
			cin >> id;
			if (id > total) {
				cout << "\nEntered wrong credentials";
				continue;
			}
			first[id].remove_assignment(opt);
			flag = false;
		} while (flag);
	
	}
	else if (opt == 6) {
		
		cout << "\nEnter student ID: ";
		cin >> opt;
		bool flag = true;
		do {
			cout << "\nEnter the index of class: ";
			cin >> id;
			if (id > total) {
				cout << "\nEntered wrong credentials";
				continue;
			}
			int marks, sub, assig;
			cout << "\nEnter the marks: ";
			cin >> marks;
			cout << "\nEnter subject: ";
			cin >> sub;
			cout << "\nEnter assignment number: ";
			cin >> assig;
			if (!first[id].book.insertmarks(marks, sub, assig)) {
				cout << "\nAssignment's are insufficent add  more assignments";
			}
			flag = false;
		} while (flag);

		
		
	}
	else if (opt == 7) {
		cout << "\nEnter student ID: ";
		cin >> opt;
		bool flag = true;
		char ch;
		do {
			cout << "\nEnter the index of class: ";
			cin >> id;
			if (id > total) {
				cout << "\nEntered wrong credentials";
				continue;
			}
			cout << "\nEnter grade: ";
			cin >> ch;
			cout << "\nEnter subject: ";
			cin >> opt;
			first[id].book.insertgrade(opt, ch);
			flag = false;
		} while (flag);
	}
	else if (opt == 8) {
		if (total == 0) {
			cout << "\nNo class is created";
			teacher_menu();
		}
		cout << "\nEnter the class id: ";
		cin >> opt;
		cin.ignore();
		cout << "\nEnter the students name: ";
		cin.get(arr, 20);
		check = true;
		fstream input("student.bin",ios::in| ios::out | ios::binary|ios::beg);
		while (input.read((char*)&tem, sizeof(tem))) {
			if (passwordmatcher(arr, tem.getname())) {
				for (int i = 0; i < 5 &&check ; i++) {
					if (tem.cla[i] == opt) {
						first[this->return_class_index(opt)].addstudent(tem);
						check = false;
					}
					
				}
			}
			if (!check) {
				break;
			}	
		}



		input.close();
	}
	else if (opt == 9) {
		cout << "\nEnter the class id: ";
		cin >> opt;
		cin.ignore();
		cout << "\nEnter the students name: ";
		cin.get(arr, 20);
		check = true;
		fstream input("student.bin", ios::in | ios::out | ios::binary | ios::beg);
		while (input.read((char*)&tem, sizeof(tem))) {
			if (passwordmatcher(arr, tem.getname())) {
				for (int i = 0; i < 5 && check; i++) {
					if (tem.cla[i] == opt) {
						first[this->return_class_index(opt)].delete_student(tem.id);
						tem.cla[i] = 0;
						check = false;
					}
				}
			}
			if (!check) {
				break;
			}
		}
	
	}
	else if (opt == 10) {
		cout << "\nEnter the class ID: ";
		cin >> opt;
		cin.ignore();
		cout << "\nEnter the students name: ";
		cin.get(arr, 20);
		cout << "\nFollowing is the work submitted:\n";
		cout<<first[this->return_class_index(opt)].s[first[this->return_class_index(opt)].return_student_index(arr)].sub.work;
	}
	else if (opt == 11) {
		this->menu();
	}
	


	cout << "\nPress 1 for teachers menu and press anyother key to logout";
	cin >> opt;
	if (opt == 1) {
		teacher_menu();
	}
	else {
		this->write_classes();
		exit(0);
	}
}


void googleclassroom::student_menu() {
	int opt;
	string nam;
	cout << "\n1-View enrolled classes";
	cout << "\n2-View assignments";
	cout << "\n3-submit assignment";
	cout << "\n4-view marks";
	cout << "\nChoice: ";
	cin >> opt;
	if (opt == 1) {
		cout << "\nEnrolled classes are: ";
		for (int i = 0; i < total; i++) {
			first[i].display();
		}
	}
	else if (opt == 2) {
		bool flag = true;
		do {
			cout << "\nEnter the subject index: ";
			cin >> opt;
			if (first[opt].total_assignments == 0) {
				cout << "\nNo assignment has been uploaded";
				break;
			}
			if (opt > total) {
				cout << "\nWrong credentials try again(subject value increases the total): ";
				continue;
			}
			cout << "\nEnter the assignment number: ";
			cin >> opt;
			if (first[opt].total_assignments > opt) {
				cout << "\nWrong credentials try again(assignment value increases the total): ";
				continue;
			}
			flag = false;
		} while (flag);
		first[opt].assign[opt].display();
	}
	else if (opt == 3) {

		cout << "\nHow do you want to upload";
		cout << "\n1-text file\n2-text";
		cin >> opt;
		cin.ignore();
		cout << "\nEnter the text:";
		getline(cin, nam);
		if (opt == 1) {
			stud.sub.upload_file(nam,stud.id);
			
		}
		else if (opt == 2) {
			stud.sub.upload_text(nam,stud.id);
		}
	}
	else if (opt == 4) {
		cout << "\nEnter the class ID: ";
		cin >> opt;
		cout << "\nStudent IDS: \n";
		for (int i = 0; i < first[this->return_class_index(opt)].total_students; i++) {
			cout <<	i <<"-" << first[this->return_class_index(opt)].s[i].id<<endl;
		}
		first[this->return_class_index(opt)].book.display();
	}
	cout << "\nPress 1 for student menu and press any other key to exit";
	cin >> opt;
	if (opt == 1) {
		this->student_menu();
	}
	
	else {
		exit(0);
	}
}

