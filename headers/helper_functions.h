#pragma once
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------------------------
class checkpass {
public:
	static void menu_admin()
	{

		cout << "                         Press the number below according to your wish " << endl;
		cout << "                                 Press 1 for Add a Doctor" << endl;
		cout << "                                 Press 2 for Delete a Doctor " << endl;
		cout << "                                 Press 3 for View a Doctor " << endl;
		cout << "                                 Press 4 for View Patients's Data " << endl;
		cout << "                                 Press 5 for edit a doctor " << endl;
		cout << "                                 Press 6 for View Doctor's Availability and editing in his Availability " << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}
	static bool check_password(string pass)
	{
		int size;bool a, b, c, d;
		for (int i = 0;pass[i] != '\0';i++)
		{
			if (isupper(pass[i]))
			{
				a = true;
				break;
			}
			else a = false;
		}
		for (int j = 0;pass[j] != '\0';j++)
		{
			if (islower(pass[j]))
			{
				b = true;
				break;
			}
			else b = false;
		}
		for (int k = 0;pass[k] != '\0';k++)
		{
			if (isdigit(pass[k]))
			{
				c = true;
				break;
			}
			c = false;
		}
		for (int i = 0; pass[i] != '\0';i++)
		{
			if (pass[i] == '@' || pass[i] == '#' || pass[i] == '!' || pass[i] == '~' || pass[i] == '$' || pass[i] == ' % '
				|| pass[i] == ' ^ ' || pass[i] == ' & ' || pass[i] == ' * ' || pass[i] == '(' || pass[i] == ')' || pass[i] == ' - ' || pass[i] == ' + ' || pass[i] == ' / ' ||
				pass[i] == '.')
			{
				d = true;
				break;
			}
			else d = false;
		}
		if (a == true && b == true && c == true && d == true)
		{
			return true;
		}
		else return false;
	}
	static void patient_menu()
	{
		cout << "                        Press 1 for reset the password ";
		cout << endl;
		cout << "                        Press 2 for Search Doctor ";
		cout << endl;
		cout << "                        Press 3 for check Charges ";
		cout << endl;
		cout << "                        Press 4 for Update the appointment ";
		cout << endl;
		cout << "                        Press 5 for change their profile detail ";
		cout << endl;
		cout << "                        Press 6 for Book in_person or video consulations ";
		cout << endl;
		cout << "                        Press 7 for check his scheduled appointment  ";
		cout << endl;
		cout << "                        Press 8 for  recharge their account  ";
		cout << endl;
		cout << "                           Press 9 for see appoint_status ";
		cout << endl;
		cout << "                          if press another key it will exit ";
		cout << endl;
	}
	static void doctor_menu()
	{
		cout << "                          Press 1 for addition of another doctor ";
		cout << endl;
		cout << "                          Press 2 Edit in profile ";
		cout << endl;
		cout << "                          Press 3 for view doctor ";
		cout << endl;
		cout << "                          Press 4 for  appointment_status";
		cout << endl;
	}
	
};