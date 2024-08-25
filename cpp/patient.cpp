#include "patient.h"
#include"in_person.h"
#include"video_consultation.h"
#include"jazz_cash.h"
#include"bank_transfer.h"
#include"e_transaction.h"
#include"easy_paisa.h"
#include"pak_pay.h"
#include"union_pay.h"
#include"register_iss_patient.h"


patient :: patient()
{
	
		this->balance = 4000;
}
//---------------------------------------------------------------------------------------------------------------------------------------------
patient::patient(string name, int id, string cnic, long int contact_num, string password, string user_name, string con_pass,int bb,bool a)
{
	strcpy_s(this->name, name.c_str());
	strcpy_s(this->cnic, cnic.c_str());
	this->id = id;
	this->contact_num = contact_num;                               //constructor for patient class
	strcpy_s(this->password, password.c_str());
	strcpy_s(this->user_name, user_name.c_str());
	strcpy_s(this->conf_pass, con_pass.c_str());
	this->balance = bb;
	this->appoint_status = a;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
int patient::get_patbalance()
{
	return this->balance;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
void patient::set_balance(int x)
{
	this->balance = x;
}
//------------------------------------------------------------------------------------------------------------------------------------
 
void  patient::dis_pat_data(string a)
{
	patient val;
	ifstream filen(appointment_file, ios::binary);
	while (filen.read((char*)&val, sizeof(patient)))
	{
		if (strcmp(this->cnic, val.get_Pcnic().c_str()))
		{

			cout << " Name of Respective Patient is :" << this->name << endl;
			cout << endl;
			cout << " ID of the Patient :" << this->id << endl;
			cout << endl;
			cout << " CNIC of the Patient :" << this->cnic << endl;
			cout << endl;
			cout << " Contact number of the Patient is :" << this->contact_num << endl;
			cout << endl;
			cout << " Username of the Patient Account is :" << this->user_name << endl;
			cout << endl;
			appointment ass;
			ifstream filen(appointment_file, ios::binary);
			while (filen.read((char*)&ass, sizeof(appointment)))
			{
				if (strcmp(this->cnic, ass.get_patcnic().c_str()))
				{
					cout << " Appointment  status : " << ass.appoint_status;
					string hum = "Approve";
					if (ass.appoint_status == hum.c_str())
					{
						cout << " Give the feedback in int upto 5 " << endl;
						int fed;
						cin >> fed;
						feedback feed;
						feed.set_feedback(fed);
					}
				}
				filen.close();
				break;
			}
		}
		else cout << " Data was not correct ";
	}
}

//----------------------------------------------------------------------------------------------------------------------------------------------
bool patient::readObject(string fileName, string username, string password) //Function for reading username and password
{
	patient temp;
	ifstream patient_file(fileName, ios::binary);
	while (patient_file.read((char*)&temp, sizeof(temp))) {
		if (temp.get_username() == username.c_str() && temp.get_password() == password.c_str()) {  //condition to match username and password from file
			patient_file.close();
			return true;
		}
	}
	return false;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
static void patient_switcher()
{
	int i;
	patient p;doctor  d;
	cin >> i;
	switch (i)
	{
	case 1:
	{
		cout << " Enter new password " << endl;
		string val;
		string cnic;
		cnic = p.get_Pcnic();
		cin >> val;
		p.reset_password(val,cnic);
		break;
	}
	case 2:
	{
		cout << " Press 1  for searching doctor through Category " << endl;
		cout << " Press 2 for searching doctor through Area " << endl;
		cout << " Press 3 for searching doctor through Hospital " << endl;
		int w;
		cin >> w;
		switch (w)
		{
		case 1:
		{ string v;
			cout << " Enter the category :";
		cin >> v;
		p.search_doctor(v);
			break;
		}
		case 2:
		{
			string g;
			cout << " Enter the name of Area :";
			cin >> g;
			p.search_doctor(g);
			break;
		}
		case 3:
		{
			string h;
			cout << " Enter the name of hospital :";
			cin >> h;
			p.search_doctor(h);
			break;
		}
		}
		break;
	}
	case 3:
	{
		cout << "Enter speciality of doctor for checking charges :";
		string check;
		cin >> check;
		cout<<d.get_charges(check);

		break;
	}
	case 4:
	{
		cout << " add status ";
		string hlo;cin >> hlo;
		p.update_appoint(hlo);                                                                                                                                                                                                                                                              
		break;
	}
	case 5:
	{
		p.update_profile();
		cout << " Your profile is updated " << endl;
		break;
	}
	case 6:
	{
		cout << " Enter the speciality of doctor for video or in_person consulation ";
		string c;cin >> c;
		p.search_doctor(c);
		break;
	}
	case 7:
	{
		patient a;
		cout << " Enter the status  of doctor :" << endl;
		string variable;
			cin >> variable;
		a.dis_pat_data(variable);
		break;
	}
	case 8:
	{
		cout << " Enter New balance :";
		int bal;cin >> bal;
		p.set_balance(bal);
		cout << "Your balance is updated " << endl;
		break;
	}
	case 9:
	{
		patient a;
		a.get_appo_status();
		break;
	}
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
void  patient ::get_appo_status() {
	for (int i = 0;i < 35;i++)
	{
		cout << this->appoint_s[i];
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
void patient::update_profile()
{
	fstream myhmm(patient_filename, ios::in | ios::out | ios::binary);
	while (myhmm.read((char*)this, sizeof(patient)))
	{ 
	patient p;
	cout << "Enter the name :";
	string name;cin >> name;
	strcpy_s(this->name, name.c_str());
	cout << " Enter the cnic :";
	string cnic;cin >> cnic;
	strcpy_s(this->cnic, cnic.c_str());
	cout << " Change the password :" << endl;
	string password; cin >> password;
	strcpy_s(this->password, password.c_str());
	cout << " Change the user_name :" << endl;
	string user_name;cin >> user_name;
	strcpy_s(this->user_name, user_name.c_str());
	int current = myhmm.tellg();
	int oneblock = sizeof(patient);
	myhmm.seekg(current - oneblock);
	myhmm.write((char*)this, sizeof(patient));
	break;
	}myhmm.close();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void patient::update_appoint(string c)
{
	appointment appo;
	fstream filek(appointment_file, ios::in | ios::out | ios::binary);
	while (filek.read((char*)&appo, sizeof(appointment)))
	{
		if (appo.get_patcnic().c_str() ==c.c_str())
		{
			string name;
			cout << " Enter the new updation ";
			cin >> name;
			appo.set_appointstatus(name.c_str());
		}
		else if (appo.get_patcnic().c_str() != this->cnic)
		{
			cout << " Cnic not matched " << endl;
			break;
		}
	int current = filek.tellg();
	int oneblock = sizeof(appo);
	filek.seekg(current - oneblock);
	filek.write((char*)&appo, sizeof(appo));
}filek.close();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
	void patient :: login()
	{
		bool a;
		string username, password;
		cout << " Enter your Email :"; cin >> username;
		cout << endl;
		cout << " Enter your Passwrod :"; cin >> password;
		a = readObject(patient_filename, username, password); // here is check whether account match or not
		
		if (a == true)
		{
			char c;
			cout << " You are logined Now" << endl;
			do {

				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				checkpass::patient_menu();  //function for displaying menu of admin
				patient_switcher();
				cout << " ---------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << " If You want to process the function further press Y else N" << endl;
				cin >> c;
			} while (c == 'Y');
		}
		else if (a == false)
		{
			cout << " not logined, please register your account" << endl;
			register_iss1::register_issue_p();
				}
	}
//--------------------------------------------------------------------------------------------------------------------------------------------------
	void patient ::ser_appo()
	{
		appointment a1;
		fstream filen(appointment_file, ios::in | ios::out | ios::binary);
		while (filen.read((char*)&a1, sizeof(appointment)))
		{
			string b = "Approve";
			if (strcmp(a1.appoint_status, b.c_str()))
			{
				strcpy_s(this->appoint_s, b.c_str());
			}
			break;
		}
		filen.close();
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------
	void patient :: register_him()    //Register  function  for Patient
	{
		string name;int id;long int contact;string p, cnic, usn, cp;bool dfc, pass_check, check2, check;bool check3;
		cout << "                                               Enter your information : " << endl;
		cout << " Enter your user_name for the Account :  ";
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
				cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
				do {
					do{
					cout << "Set Your Password : which include number,lower, upper and special character and consistes 8 digit :" << endl;
					cout << endl;
					cin >> p;
					check3 = checkpass::check_password(p);
					pass_check = this->set_pass(p);
					if (check3 == false)
					{

						cout << " incorrect password type : add uppercases,lowercases and special characters " << endl;
						cout << endl;
					}
					if (pass_check == false)
					{
						cout << "Enter 8 digit correct password" << endl;
						cout << endl;
					}
				} while (pass_check == false);
			} while (check3 == false);
				do {
					cout << " Confirm your password :  ";
					cin >> cp;
					check2 = this->confirm_pass(cp);                   //Apply conditions for checking input of correct password
					if (check2 == false)
					{
						cout << " Enter your correct Again " << endl;
						cout << endl;
					}
					if (p != cp)
					{
						cout << " Your password is incorrect " << endl;
						cout << endl;
					}
				} while (check2 == false);
			} while (p != cp);
			check = readObject(doctor_filename, usn, cp);
			if (check == true)
			{
				cout << " Sorry You have already Registered " << endl;
			}
			else if (check == false)
			{
				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "                             Congrats You are registered to OLADOC family , Happy to see you in OLADOC :)" << endl;
				cout << " Now Enter your name :  ";
				cin >> name;
				this->set_name(name);
				cout << "Enter the id :  ";
				cin >> id;
				this->set_id(id);
				cout << " Enter your Contact Number ;  ";
				cin >> contact;
				this->set_cont_num(contact);
				set_balance(3500);
				cout << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

				FH_insertObject(); //For Data insertion after the registration of Doctor his Data automatically inserted.
			}
		}
	}
//------------------------------------------------------------------------------------------------------------------------------------------------
	void patient :: reset_password(string new_password,string hmm)
	{
		
		fstream filo(patient_filename, ios::in | ios::out | ios::binary);
		while(filo.read((char*)this,sizeof(patient)))
		{ 
			patient p;
			if(p.cnic==hmm.c_str())
			{
				strcpy_s(this->password, new_password.c_str());  // Password change function for the patient
				
			}
			int current = filo.tellg();
			int oneblock = sizeof(p);
			filo.seekg(current - oneblock);
			filo.write((char*)&p, sizeof(patient));
			break;
		}filo.close();

	}
//------------------------------------------------------------------------------------------------------------------------------------------------
	string patient::get_Pname()
	{
		return this->name;
}
	//----------------------------------------------------------------------------------------------------------------------------------------------
	string patient::get_Pcnic()
	{
		return this->cnic;
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------
	void  funformoney(double a)
	{
		cout << "Enter the type of Payment :" << endl;
		cout << "Press 1 = E_transaction " << endl;
		cout << "Press 2 = Bank_transfer " << endl;
		int w;
		cin >> w;
		switch (w)
		{
		case 1:
		{
			cout << "Through  1= jazzcash " << endl;
			cout << " Through 2 =easypaisa " << endl;
			int num;
			cin >> num;
			switch (num)
			{
			case 1:
			{
				payment* p;
				jazz_cash j;
				p = &j;
				p->send_money(a);
				cout << "Your money is transfered thrrough Jazz-Cash " << endl;
					break;
			}
			case 2:
			{
				payment* p;
				easy_paisa ef;
				p = &ef;
				p->send_money(a);
				cout << "Your money is transfered thrrough Easy_paisa " << endl;
				break;
			}
			}
			break;
		}
		case 2:
		{
			cout << "Through  1= Pak_pay " << endl;
			cout << " Through 2 = Union pay " << endl;
			int num;
			cin >> num;
			switch (num)
			{
			case 1:
			{
				payment* p;
				pak_pay j;
				p = &j;
				p->send_money(a);
				cout << "Your money is transfered thrrough Pak_pay account " << endl;
				break;
			}
			case 2:
			{
				payment* p;
				union_pay ef;
				p = &ef;
				p->send_money(a);
				cout << "Your money is transfered thrrough Union_pay account " << endl;
				break;
			}
			}
			break;
		}
		}
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------
	int patient::get_patientday()
	{
		return this->day;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------
	void patient ::FH_insertObject() {
		ofstream myFile(patient_filename, ios::binary | ios::app);
		if (myFile.write((char*)this, sizeof(patient))) {
			cout << "Success! Object Updated." << endl;
			myFile.close();                                               //insert object in Patient file
		}
		else {
			cout << "Failed! Object Not Updated." << endl;
		}
	}
//----------------------------------------------------------------------------------------------------------------------------------------------
	void  patient :: pat_dis_BFH(int id)
	{
		patient temp;
		ifstream myfile(patient_filename, ios::binary);
		while (myfile.read((char*)this, sizeof(patient)))
		{
			if (temp.get_id() == id)
			{
				cout << " Enter your cnic :";
				string y;
				cin >> y;
				temp.dis_pat_data(y);
			}
			else cout << "Any patient do not have such id " << endl;
            myfile.close();
		}
	}
//-----------------------------------------------------------------------------------------------------------------------------------------------
	void patient :: search_doctor(string specialty)
	{
		doctor logo;
		fstream myfile(doctor_filename,ios:: in|ios:: out |ios::binary);
		while (myfile.read((char*)&logo, sizeof(doctor)))
		{
			if ((logo.get_specialty() == specialty.c_str()) || logo.get_area() == specialty.c_str() || logo.get_hopital_name() == specialty.c_str())
			{
				logo.display_doctor();
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				char y;
				cout << " If you want to book appointment press Y else N ";
				cin >> y;
				switch (y)
				{
				case 'Y':
				{
				if (logo.slot_array[1] == true)
					{
						cout << "Slot 1 " << "of time 7Am to 8am is not empty " << endl;
					}
					else cout << "Slot 1 " << "of time 7Am to 8am is empty " << endl;
					if (logo.slot_array[2] == true)
					{
						cout << "Slot 2 " << "of time 8Am to 9Am is not empty " << endl;
					}
					else cout << "Slot 2 " << "of time 8Am to 9Am is empty " << endl;
					if (logo.slot_array[3] == true)
					{
						cout << "Slot 3 " << "of time 9Am to 10Am is not empty " << endl;
					}
					else cout << "Slot 3 " << "of time 9Am to 10Am is empty " << endl;
					if (logo.slot_array[4] == true)
					{
						cout << "Slot 4 " << "of time 10Am to 11Am is not empty " << endl;
					}
					else cout << "Slot 4 " << "of time 10Am to 11Am is empty " << endl;
					if (logo.slot_array[5] == true)
					{
						cout << "Slot 5 " << "of time 11Am to 12pm is not empty " << endl;
					}
					else cout << "Slot 5 " << "of time 11Am to 12pm is empty " << endl;
					//-------------------------------------------------------------------	
					
					int i;
					cout << " select type of appointment " << endl;
					cout << " Press 1 = video_consulation " << endl;
					cout << " Press 2 = in_person " << endl;
					int type;
					cin >> type;
					switch (type)
					{
					case 1:
					{
						double last_pay = 0;//logo.get_charges() * 0.3;
						video_consultation v1;
						int i;appointment app3;
					do {
						cout << " Press slot number ";
						cin >> i;
						if (i <= 5)
						{
							if (logo.slot_array[i] == true)
							{
								cout << "Already filled, Book another slot " << endl;

							}

							else if (logo.slot_array[i] == false)
							{
								logo.slot_array[i] = true;

								video_consultation app4;
								app4.funwriteforappoint(this->get_Pname(), this->get_Pcnic(), logo.get_Dcnic(), logo.get_Dname());
								app4.write_appointfile();

								cout << "Your slot is booked " << endl;
								funformoney(last_pay);
								break;
							}
							

							
						}
						else {
							cout << "There is no slot " << endl;
						}
					}
						while (logo.slot_array[i] == true);
				
							
						break;
					}
					case 2:
					{
						double yt = 0;//logo.get_charges();
						do {
							cout << " Press slot number ";
							cin >> i;
							if (i <= 5)
							{
								if (logo.slot_array[i] == true)
								{
									cout << "Already filled, Book another slot " << endl;

								}

								else if (logo.slot_array[i] == false)
								{
									logo.slot_array[i] = true;

									in_person app4;
									app4.funwriteforappoint(this->get_Pname(), this->get_Pcnic(), logo.get_Dcnic(), logo.get_Dname());
									app4.write_appointfile();
									
									cout << "Your slot is booked " << endl;
									funformoney(yt);
									break;
								}
								
							}
							else {
								cout << "There is no slot " << endl;
							}
						} while (logo.slot_array[i] == true);
						break;
					}
					}

					break;
				}
				case 'N':
				{
					cout << "NO slot Booked" << endl;
					break;
				}
				}
			
			}
			
		else
			{
			cout << " Doctor was not found, Please enter correct information " << endl;
			break;
			}
			int current = myfile.tellg();
			int oneblock = sizeof(logo);
			myfile.seekg(current - oneblock);
			myfile.write((char*)this, sizeof(logo));
			
		}myfile.close();
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------

	//------------------------------------------------------------------------------------------------------------------------------------------------------------------