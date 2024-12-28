#include"headers.h"



class Register{
private:
	 
	char  cnic[15] ,password[10],name[30], email[30];
	
public:

	Register() 
	{
		cnic[0] = '\0';
		password[0] = '\0';
		name[0] ='\0';
		email[0] = '\0';
	}
	void setname(char*);
	void setcnic(char*);
	void setpassword(char*,int);
	void setemail(char*);
	char* getcnic();
	char* getname();
	char* getpassword();
	char* getemail();
	void info_for_doctor();
	void display();
};



class info_doc
{
private:
	char city[30], special[30];
	int exp;
public:
	info_doc()
	{
		city[0] = '\0';
		special[0] = '\0';
		exp = 0;
	};
	void setcity(char*);
	void setspecial(char*);
	void setexp(int);
	char* getcity();
	char* getspecial();
	int getexp();
	~info_doc()
	{
		delete this;
	}
};









int Size_of(char*);

void read_write_registera(Register& da, string file);

void Registeration(string);

bool check_for_password(char*);

string convertToString(char* a, int size);







