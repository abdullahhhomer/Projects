#pragma once


class submission {
public:
	string work;
	string id;
	submission() {

	}
	bool upload_file(string fil,string id) {
		string data;
		ifstream file(fil);
		if (file.is_open()) {
			while (getline(file, data)) {
				this->work += data+'\n';
			}
			cout << "\nFile is uploaded on the classroom";
			return true;
		}
		else {
			cout << "\nFile doesn't exist on system";
			return false;
		}
		file.close();
		this->write();
	}

	void upload_text(string text,string id) {
		this->work = text;
		this->write();
	}

	void write() {
		ofstream file("submission.txt");
		if (file.is_open()) {
			file.write( (char*)&*this, sizeof(*this));
		}
		file.close();
	}

	void download() {
		
	}

	void operator=(int i) {
		this->work = " ";
		this->id = " ";
	}

	void operator=(submission& obj) {
		this->work = obj.work;
		this->id = obj.id;
	}
};