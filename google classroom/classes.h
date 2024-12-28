#pragma once

#include"assignment.h"
#include"student.h"
#include"teacher.h"
#include "gradebook.h"


int str_length_return_(char* arr) {
	int size = 0;
	while (arr[size] != '\0') {
		size++;
	}
	++size;
	return size;
}




bool passwordmatcher_(char* arr1, char* arr2) {
	bool flag = true;
	if (str_length_return_(arr1) == str_length_return_(arr2)) {
		flag = true;
	}
	else {
		flag = false;
		return flag;
	}
	for (int i = 0; i < str_length_return_(arr1); i++) {
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




class classes {
public:
	student s[50];
	assignment assign[5]; 
	teacher teach;
	gradebook book;
	char description[100];
	char subject[100];
	
	int total_students, total_assignments;
	int id;

	classes() {
		total_students = 0;
		total_assignments = 0;
		for (int i = 0; i < 100; i++) {
			description[i] = '\0';
			subject[i] = '\0';
		}
		
	}
	classes(int id):id(id) {
		for (int i = 0; i < 50; i++) {
			s[i] = 0;
		}
		total_students = 0;
		total_assignments = 0;
	}
	
	void addstudent(student& obj) {
		if (total_students > 49) {
			cout << "\nMaximum students are registered";
			return;
		}
		s[total_students] = obj;
		total_students++;
		cout << "\nStudent registered";
	}


	void delete_student(string id) {
	

		
	}
	


	void addassignment(assignment obj) {
		

			
	}

	void remove_assignment(int num) {
		
	}

	int return_student_index(char* name) {
		for (int i = 0; i < total_students; i++) {
			if (passwordmatcher_(name, s[i].getname())) {
				return i;
			}
		}
	}
	
	void write_in_file() {
		fstream obj1("classes.bin", ios::out |ios::in| ios::app | ios::binary);
		if (obj1.is_open()) {
			obj1.write((char*)&total_students, sizeof(total_students));
			obj1.write((char*)&total_assignments, sizeof(total_students));
			obj1.write((char*)&teach, sizeof(teach));
			obj1.write((char*)&id, sizeof(id));
			obj1.write((char*)&description, sizeof(description));
			obj1.write((char*)&subject,sizeof(subject));
			for (int i = 0; i < total_students;i++) {
				obj1.write((char*)&s[i], sizeof(s[i]));
			}
			for (int i = 0; i < total_assignments; i++) {
				obj1.write((char*)&assign[i], sizeof(assign[i]));
			}
			
		}
		else {
			cout << "\nError while opening file";
		}
		obj1.close();
	}







	void operator=(classes& obj) {
		total_students = obj.total_students;
		total_assignments = obj.total_assignments;
		for (int i = 0; description[i]!='\0'; i++) {
			description[i] = obj.description[i];
		}
		
		for (int i = 0; subject[i]!='\0'; i++) {
			subject[i] = obj.subject[i];
		}
		
		teach = obj.teach;	
		id = obj.id;
		this->book = obj.book;
		for (int i = 0; i < obj.total_students; i++) {
			this->s[i] = obj.s[i];
		}
		for (int i = 0; i <obj.total_assignments; i++) {
			this->assign[i] = obj.assign[i];
		}

	}

	void display() {
		cout << "\nClass ID:" << id;
		cout << "\nTotal students: "<<total_students;
		cout << "\nTotal assignments: " << total_assignments;
		cout << "\nClass description: " ;

		for (int i = 0;  str_length_return_(description); i++) {
			cout << description[i];
		}
		cout << "\nSubject: " ;
		for (int i = 0; str_length_return_(subject); i++) {
			cout << subject[i];
		}
	}

};