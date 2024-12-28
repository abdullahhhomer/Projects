#include"login.h"
void mod()
{
	system("Color a");
	Register r;
	login l;
	int n;
	cout << "\nWhich operations you want to perform? ";
	cout << "\n1-login\n2-Register: ";
	cin >> n;
	
	switch (n)
	{
	case 1:
		cout << "\nEnter you're designantion: ";
		cout << "\n1-DOCTOR\n2-Patient: ";
		cin >> n;
		if (n == 1)
		{
			l.login_in("doctor");
		}
		else
		{
			l.login_in("patient");
		}
		break;

	case 2:
		cout << "\nEnter you're designantion: ";
		cout << "\n1-DOCTOR\n2-Patient: ";
		cin >> n;
		if (n == 1)
		{
			Registeration("doctor");
		}
		else
		{
			Registeration("patient");
		}
		break;
	}
}