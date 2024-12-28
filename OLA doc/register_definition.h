#include"register.h"


void Register::setname(char* n)
{
	for (int i = 0; i < Size_of(n); i++)
	{
		name[i] = n[i];
	}
}
void Register::setcnic(char* nic)
{

	for (int i = 0; i < 15; i++)
	{
		cnic[i] = nic[i];
	}
}
void Register::setpassword(char* temp,int size)
{

	for (int i = 0; i < size; i++)
	{
		password[i] = temp[i];
	}
}
void Register::setemail(char* n)
{
	for (int i = 0; i < Size_of(n); i++)
	{
		email[i] = n[i];
	}
}


char* Register::getcnic()
{
	return cnic;
}
char* Register::getname()
{
	return name;
}
char* Register::getpassword()
{
	return password;
}
char* Register::getemail()
{
	return email;
}


void Register::display()
{
	cout << "\n***********************************************************************";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n*						                                             *";
	cout << "\n***********************************************************************";
	cout << "\n\n\n\n\n\n\n";
	cout << "\nName: ";
	for (int i = 0; i < Size_of(name); i++)
	{
		cout << name[i];
	}
	cout << "\nEmail: ";
	for (int i = 0; i < Size_of(email); i++)
	{
		cout << email[i];
	}
	cout  << "\nCNIC: ";
	for (int i = 0; i < Size_of(cnic); i++)
	{
		cout << cnic[i];
	}
}

void Register::info_for_doctor()
{
	info_doc* ptr=new info_doc;
	char* arr=new char[30];
	int e;
	cin.ignore();
	cout << "\nEnter the city: ";
	cin.get(arr, 30);
	ptr->setcity(arr);
	cin.ignore();
	cout << "\nEnter you're specialization: ";
	cin.get(arr, 30);
	ptr->setspecial(arr);
	cout << "\nEnter you're experience: ";
	cin >> e;
	ptr->setexp(e);
	delete[] arr;

}


void info_doc::setcity(char* ch)
{
	for (int i = 0; i < Size_of(ch); i++)
	{
		city[i] = ch[i];
	}

}
void info_doc::setspecial(char* ch)
{
	for (int i = 0; i < Size_of(ch); i++)
	{
		special[i] = ch[i];
	}
}

void info_doc::setexp(int e)
{
	exp = e;
}


char* info_doc::getcity()
{
	return city;
}
char* info_doc::getspecial()
{
	return special;
}

int info_doc::getexp()
{
	return exp;
}



int Size_of(char* arr)
{
	int i = 0;
	int size = 0;
	while (arr[i] != '\0')
	{
		i++;
		size++;
	}
	size++;
	return size;
}




void Registeration(string file)
{
	Register da;
	char pas[10], temp[10]{},data[30]{};
	char ptr[15];
	cin.ignore();
	cout << "\nEnter your Name: ";
	cin.get(data,30);
	da.setname(data);
	cin.ignore();
	cout << "\nEnter you're CNIC: ";
	cin.get(ptr, 15);
	da.setcnic(ptr);
	cin.ignore();
	cout << "\nEnter you're new password: ";
	cin.get(pas,10);
	bool flag = check_for_password(pas);
	for (int i = 0; i < strlen(pas); i++)
	{
		temp[i] = pas[i];
	}
	while (!flag)
	{
		cin.ignore();
		cout << "\nYou're password should have special,capital,small and numeric values: ";
		cin.get(pas, 10);
		flag = check_for_password(pas);
	}
	while (flag)
	{
		cin.ignore();
		cout << "\nEnter you're password again for confirmation: ";
		cin.get(pas,10);
		if (strlen(temp) == strlen(pas))
		{
			for (int i = 0; i < strlen(pas); i++)
			{
				if (temp[i] != pas[i])
				{
					flag = true;
					break;
				}
				else
				{
					flag = false;
				}
			}
		}
		else
		{
			flag = true;
		}
	}
	da.setpassword(pas,sizeof(pas));
	cin.ignore();
	cout << "\nEnter you're valid email address: ";
	cin.get(data, 30);
	da.setemail(data);
	if (file == "doctor")
	{
		da.info_for_doctor();
	}
	read_write_registera(da, file);
}

void read_write_registera( Register& da,string file)
{
	Register temp;
	fstream write;
	bool flag = false;
	write.open(file + ".txt", ios::binary  | ios::in | ios::out | ios::beg);
	if (write.is_open())
	{
		
		while (write.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getcnic() == da.getcnic() || temp.getemail() == da.getemail())
			{
				cout << "\nAlready registered!!\n";
				flag = true;
				//da.display();
			}
			else
			{
				cout << "\nRegisteration is successful!";
				flag = false;
				da.display();
				break;
			}
			
		}
		if (flag )
		{
			cout << "\nEnter your're data again!!!!";
			cin.ignore();
			cin.get();
			system("cls");
			Registeration(file);
		}
		write.close();
		write.open(file + ".txt", ios::binary | ios::in | ios::out | ios::app);
		write.write((char*)&da, sizeof(da));
	}
	write.close();
}




bool check_for_password(char* data)
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	for (int i = 0; i < strlen(data); i++)
	{
		if ((data[i] > 32 && data[i] <= 47) || (data[i] >= 58 && data[i] <= 64) || (data[i] >= 91 && data[i] <= 96) || (data[i] >= 123 && data[i] <= 126))
		{
			flag1 = true;
		}
		else if (data[i] >= 48 && data[i] <= 57)
		{
			flag2 = true;
		}
		else if (data[i] >= 65 && data[i] <= 90)
		{
			flag3 = true;
		}
		else if (data[i] >= 97 && data[i] <= 122)
		{
			flag4 = true;
		}
	}
	if (flag1 && flag2 && flag3 && flag4)
	{
		return true;
	}
	else
	{
		return false;
	}
}






string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}






void reg()
{
	Registeration("doctor");
}
















