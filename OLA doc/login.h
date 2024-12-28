#include"headers.h"
#include"register_definition.h"
class login : public Register {
public:
	login(){}
	void login_in(string);

};

void login::login_in(string file)
{
	Register r;
	char temp[30];
	bool flag = false;
	cin.ignore();
	cout << "\nEnter username: ";
	cin.get(temp, 30);
	this->setname(temp);
	cin.ignore();
	cout << "\nEnter password: ";
	cin.get(temp, 30);
	this->setpassword(temp,Size_of(temp));
	fstream data(file + ".txt", ios::binary | ios::in | ios::out | ios::beg);
	while (data.read((char*)&r, sizeof(r)))
	{
		if((r.getname()==this->getname()) && (r.getpassword()==this->getpassword()))
		{
			flag = true;
			break;
		}

	}
	if (flag)
	{
		cout << "\nLogin Successful!";
	}
	else
	{
		cout << "\nYou are not registered!!!!";
	}


}