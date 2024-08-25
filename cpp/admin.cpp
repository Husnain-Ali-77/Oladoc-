#include"admin.h"
#include"helper_file_variables.h"
#include"register_fun_issue_ADMIN.h"
#include<iostream>
using namespace std;
	admin :: admin()
	{
	}
	admin::admin(string name, int id, string cnic, long int contact_num, string password, string user_name, string con_pass)
	{
		strcpy_s(this->name, name.c_str());
		this->id = id;
		strcpy_s(this->cnic, cnic.c_str());
		this->contact_num = contact_num;                   //Constructor of admin class
		strcpy_s(this->password, password.c_str());
		strcpy_s(this->user_name, user_name.c_str());
		strcpy_s(this->conf_pass, con_pass.c_str());
	}
	bool admin :: readObject(string fileName, string username, string password) //Function for reading username and password
	{
		admin temp;
		ifstream admin_filename(fileName, ios::binary);
		while (admin_filename.read((char*)&temp, sizeof(temp))) {
			if (temp.get_username() == username.c_str() && temp.get_password() == password.c_str()) {      //here is check whether account match or not
				admin_filename.close();
				return true;
			}
		}
		return false;
	}
	void admin ::login()
	{
		bool a;
		string username, password;
		cout << " Enter your Email :"; cin >> username;
		cout << endl;
		cout << " Enter your Passwrod :"; cin >> password;
		a = readObject(admin_filename, username, password);  //here is apply check to see it there login become possible or not
		if (a == true) 
		{
			cout << " You are logined Now" << endl;
			char c;
			do {

				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				checkpass::menu_admin();   //function for displaying menu of admin
				switches_admin();
				cout << " ---------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << " If You want to process the function further press Y else N" << endl;
				cin >> c;
			} while (c == 'Y');
		}
		else if (a == false)
		{
			cout << " not logined please Register your account " << endl;
			register_iss::register_issue_a();
		}
	}
	//------------------------------------------------------------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------------------------------------------------------------
	void admin::register_him()            //Register  function  for Admin
	{
		string name;int id;long int contact;string p, cnic, usn, cp;bool dfc;bool check3, check2, check;
		cout << "                                               Enter your information : " << endl;
		cout << " Enter your Email for the Account :  ";
		cin >> usn;
		this->set_username(usn);
		do {
			cout << " Enter your cnic :  ";
			cin >> cnic;
			dfc = this->set_cnic(cnic);
			if (dfc == false)
			{
				cout << "Invalid cnic,  please Enter again" << endl;
			}
		} while (dfc == false);
		if (dfc = true)
		{
			do {
				do {
					do {
						cout << "Set Your Password :  ";
						cin >> p;
						check3 = checkpass::check_password(p);
						check2 = this->set_pass(p);
						if (check3 == false)
						{

							cout << " incorrect password type : add uppercases,lowercases and special characters " << endl;
							cout << endl;
						}
						if (check2 == false)
						{
							cout << " Enter Again " << endl;
							cout << endl;
						}
					} while (check2 == false);
				} while (check3 == false);
				do {

					cout << " Confirm your password :  ";
					cin >> cp;
					this->confirm_pass(cp);               //Apply conditions for checking input of correct password

					if (p != cp)
					{
						cout << " Your password is incorrect please Enter again" << endl;
					}
				} while (check2 == false);

			} while (p != cp);
			check = readObject(admin_filename, usn, cp);
			if (check == true)
			{
				cout << "Your account is already registered " << endl;
			}
			else if (check == false)
			{
				cout << "                                   Congrats You are registered to OLADOC family , Happy to see you in OLADOC :)" << endl;
				cout << " Now Enter your name :  ";
				cin >> name;
				this->set_name(name);
				cout << "Enter the id :  ";
				cin >> id;
				this->set_id(id);
				cout << " Enter your Contact Number ;  ";
				cin >> contact;
				this->set_cont_num(contact);
				FH_insertObject(); //For Data insertion after the registration of Admin his Data automatically inserted.
				cout << "                         Congratulation Your profile Registered as a Admin " << endl;
				char c;
				do {
					cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
					checkpass::menu_admin();   //function for displaying menu of admin
					switches_admin();
					cout << " ---------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << " If You want to process the function further press Y else N" << endl;
					cin >> c;
				} while (c == 'Y');
			}
		}
	}
	//--------------------------------------------------------------------------------------------------------------------------------
	void admin :: FH_insertObject() {
		ofstream admin_file(admin_filename, ios::binary | ios::app);
		if (admin_file.write((char*)this, sizeof(admin))) {
			cout << "Success! Object Updated." << endl;      //function for the updation of object
			admin_file.close();
		}
		else {
			cout << "Failed! Object Not Updated." << endl;
		}
	}
	//--------------------------------------------------------------------------------------------------------------------------------
		void admin::switches_admin()
		{

			doctor doctor_data; patient patient_data;
			int num;
			cin >> num;
			switch (num)
			{
			case 1:
			{
				doctor_data.register_him();
				cout << " Congratulation Doctor is added to the file " << endl;
				checkpass::menu_admin();
				break;
			}
			case 2:
			{  int id;
			cout << " Enter the id of the respective Doctor :";
			cin >> id;
			doctor_data.delete_doctor(id);
			break;                                                      // these are switches for the doctor
			}
			case 3:
           {
				int id;
			cout <<  " Enter the ID of the Doctor you wanted to view :";
			cin >> id;
			doctor_data.doc_dis_BF(id);
			break;
			}
			case 4:
			{int id;
			cout << "Enter id of Patient :";
			cin >> id;
			patient_data.pat_dis_BFH(id);
				break;
			}
			case 5:
			{
				string fun;doctor ter;
				cout << "Enter the CNIC of Doctor :";
				cin >> fun;
			ter.admin_funfornewadd(fun);
				break;
			}
			case 6:
			{string yup;doctor temp;
			
				cout<< "Enter the CNIC of Doctor :";
				cin >> yup;
				temp.availability(yup);
				break;
			}
			}
		}
	//--------------------------------------------------------------------------------------------------------------------------------------------
		