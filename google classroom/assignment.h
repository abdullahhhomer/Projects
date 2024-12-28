#pragma once


class assignment {
private:
	string attached, title, description;
	double marks;


public:
	time_t tim;
	assignment() { attached = " "; }
	assignment(string title, string description, double marks) : title(title), description(description), marks(marks) {
		tim = NULL;
		attached = " ";
	}


	/*bool upload(string attached) {
		string data;
		ifstream file(attached);
		if (file.is_open()) {
			while (getline(file, data)) {
				this->attached += data;
			}
			cout << "\nFile is uploaded on the classroom";
			return true;
		}
		else {
			cout << "\nFile doesn't exist on system";
			return false;
		}
		file.close();
	}*/

	///*bool download(string down) {
	//	ofstream file(down);
	//	if (file.is_open()) {
	//		file << this->attached;
	//		cout << "\nData is downloaded";
	//		return true;

	//	}
	//	else {
	//		cout << "\nError while downloading!";
	//		return false;
	//	}
	//}*/

	//bool delete_(string file) {
	//	if (remove(file.c_str()) == 0) {
	//		cout << "\nFile is succesfully deleted from the system";
	//	}
	//	else {
	//		cout << "\nFile doesnot exist on system";
	//	}

	//}
	bool time_check() {
		time_t t = time(nullptr);
		if (t > tim) {
			return true;
		}
		else {
			return false;
		}

	}

	void display() {
		cout << "\nTitle: "<<title;
		cout << "\nTotal marks: " << marks;
		cout << "\nDescription: " << description;
	}

	void operator=(assignment& obj) {
		this->attached = obj.attached;
		this->description = obj.description;
		this->marks = obj.marks;
		this->title = obj.title;
	}

};

