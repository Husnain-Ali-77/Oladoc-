#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<Windows.h>
using namespace std;
#include"User.h"
#include"admin.h"
#include"doctor.h"
#include"patient.h"
int main()
{
	User* user_info;admin admin_data;doctor doctor_data;patient patient_data;appointment a;
	system("Color E4");
	doctor_data.fun(&a);
	cout << "---------------------------------***************************(OLADOC)************************-------------------   " << endl;
	cout << "               --------------------------*****************|||||||||||||||*******************----------------------" << endl;
	cout << "                                  ----------------*************||||||*************----------------------" << endl;
	cout << "                                                 -----------*****||*******-------------" << endl;
	cout << "                   if you want to login please Press L and if You want to register please press R" << endl;
	char press;
	cin >> press;
	switch (press)
	{
	case 'L':
	{
		int val_press;
		cout << "                            if you want to login please see below : " << endl;
		cout << "                            press 1 = login as a Admin " << endl;
		cout << "                            press 2 = login as a Doctor " << endl;
		cout << "                            press 3 = login as a Patient " << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

		cin >> val_press;

		switch (val_press)
		{
		case 1:
		{
			user_info = &admin_data;
			user_info->login();
			break;
		}
		case 2:
		{

			user_info = &doctor_data;
			user_info->login();

			break;
		}
		case 3:
		{
			user_info = &patient_data;
			user_info->login();
			break;
		}
		}
		break;

	case 'R':
	{
		int num;
		cout << "                    Select number for respective registration :" << endl;
		cout << "                               press 1 for Admin " << endl;
		cout << "                               Press 2 for Doctor " << endl;
		cout << "                               Press 3 for Patient " << endl;
		cin >> num;

		switch (num)
		{
		case(1):
		{
			admin_data.register_him();
			admin_data.login();
			break;
		}
		case(2):
		{
			doctor_data.register_him();
			doctor_data.login();
			break;
		}
		case(3):
		{
			patient_data.register_him();
			patient_data.login();
			break;
		}
		}
		break;
	}
	}
	}
	return 0;
}
