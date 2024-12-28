#pragma once
#include"Headerfiles.h"
template<class T>
T** dynamic_memory_array(int row, int col) {
	T** arr = new T * [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new T[col];
	}
	return arr;
}





class gradebook {
private:
	double** marks;
	char* grade;
	int totalstudents, totalassignments;

public:
	gradebook() {
		marks = NULL;
		grade = NULL;
		totalstudents = 0;
		totalassignments = 0;
	}
	gradebook(int totalstudents) :totalstudents(totalstudents) {
		marks = dynamic_memory_array<double>(totalstudents, 1);
		grade = new char[totalstudents];
		totalassignments = 1;
		for (int i = 0; i < totalstudents; i++) {
			grade[i] = 'I';
		}
	}



	bool insertmarks(int marks, int subject, int assignment) {
		if (assignment > this->totalassignments) {
			return false;
		}
		else {
			this->marks[subject][assignment - 1] = marks;
			return true;
		}
	}
	void addassignment() {
		double** temp = dynamic_memory_array<double>(totalstudents, totalassignments);
		for (int i = 0; i < totalstudents; i++) {
			for (int j = 0; j < totalassignments; j++) {
				temp[i][j] = this->marks[i][j];
			}
		}

		for (int i = 0; i < totalassignments; ++i) {
			delete[] marks[i];
		}
		delete[] marks;

		marks = NULL;



		marks = dynamic_memory_array<double>(totalstudents, totalassignments + 1);
		for (int i = 0; i < totalstudents; i++) {
			for (int j = 0; j < totalassignments; j++) {
				this->marks[i][j] = temp[i][j];
			}
		}
		totalassignments++;
	}

	void removeassignment(int assignment_number) {
		double** temp = dynamic_memory_array<double>(totalstudents, totalassignments);
		for (int i = 0; i < totalstudents; i++) {
			for (int j = 0; j < totalassignments; j++) {
				if (j == assignment_number) {
					continue;
				}
				temp[i][j] = this->marks[i][j];
			}
		}

		for (int i = 0; i < totalassignments; ++i) {
			delete[] marks[i];
		}
		delete[] marks;

		marks = NULL;

		marks = dynamic_memory_array<double>(totalstudents, totalassignments - 1);
		int c = 0, r = 0;



		for (int i = 0; i < totalstudents; i++, r++) {
			for (int j = 0; j < totalassignments; j++, c++) {
				if (j == assignment_number) {
					c--;
					continue;
				}
				this->marks[r][c] = temp[i][j];
			}

		}

	}

	void insertgrade(int subject, char grade) {
		this->grade[subject - 1] = grade;
	}

	void operator=(gradebook& obj) {
		this->totalassignments = obj.totalassignments;
		this->totalstudents = obj.totalstudents;
		this->marks = dynamic_memory_array<double>(totalstudents, totalassignments);
		for (int i = 0; i < totalstudents; i++) {
			for (int j = 0; j < totalassignments; j++) {
				this->marks[i][j] = obj.marks[i][j];
			}
		}
		this->grade = new char[totalstudents];
		for (int i = 0; i < totalstudents; i++) {
			this->grade[i] = obj.grade[i];
		}
	}


	void display() {
		cout << "\nGrade ";
		for (int i = 0; i < totalassignments; i++) {
			cout << " \tAssignment " << i + 1;
		}
		for (int i = 0; i < totalstudents; i++) {
			cout << "\n" <<grade[i] ;
			for (int j = 0; j < totalassignments; j++) {
				cout << " \t" << marks[i][j];
			}
		}
	}
};