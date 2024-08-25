#include "doctor.h"
#include"register_iss_doctor.h"
#include"appointment.h"
#include"dermatologist.h"
#include"gynecologist.h"
#include"oncologist.h"
#include"orthopedic.h"
#include <stdio.h>
#include<cstring>
	doctor :: doctor()
	{

	}
	doctor::doctor(string name, int id, string cnic, long int contact_num, string password, string user_name, string con_pass,
		double charges, string avail_hour, string city, string hp, string special, int experience, string location, int patient_feedback,int day)
	{
		for (int i = 0;i < 15;i++)
		{
			slot_array[i] = false;
		}
		this->days = new string[0];
		strcpy_s(this->name, name.c_str());
		this->id = id;
		strcpy_s(this->cnic, cnic.c_str());
		this->contact_num = contact_num;
		strcpy_s(this->password, password.c_str());
		strcpy_s(this->user_name, user_name.c_str());                     //Constructor of Doctor class
		strcpy_s(this->conf_pass, con_pass.c_str());
		this->charges = charges;
		this->day_num = day;
		strcpy_s(this->avail_hour, avail_hour.c_str());
		strcpy_s(this->city_name, city.c_str());
		strcpy_s(this->specialization, special.c_str());
	     strcpy_s(this->hospital_name, hp.c_str());
		this->experience = experience;
		strcpy_s(this->location, location.c_str());
		this->patients_feedback = patients_feedback;
	}

//----------------------------------------------------------------------------------------------------------------------------------------
	string doctor::get_Dname()
	{
		return this->name;
	 }
	//--------------------------------------------------------------------------------------------------------------------------------------
	void doctor::display_doctor()
	{
		cout << " Name of Respective Doctor is :" << this->name << endl;
		cout << endl;
		cout << " ID of the Doctor :" << this->id << endl;
		cout << endl;
		cout << " CNIC of the Doctor :" << this->cnic << endl;
		cout << endl;
		cout << " Contact number of the Doctor is :" << this->contact_num << endl;
		cout << endl;
		cout << " Email of the Doctor Account is :" << this->user_name << endl;
		cout << endl;
		cout << " Appointment Charges of the Doctor is :" << this->charges << endl;
		cout << endl;                                                                          //function for display of doctor
		cout << " Speciality of the Doctor :" << this->specialization << endl;
		cout << endl;
		cout << "Experience of the doctor :" << this->experience << endl;
		cout << endl;
		cout << " Location of the Doctor Clinic :" << this->location << endl;
		cout << endl;
		cout << "City name of the doctor :" << this->city_name << endl;
		cout << endl;
		cout << " Hospital name of the doctor :" << this->hospital_name << endl;
		cout << endl;
		cout << " Number of days :";
		cout << this->day_num;
		cout << " Patients feedback :" << this->patients_feedback << endl;
		cout << endl;
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------
	void doctor::edu_of_doc()
	{

	}
//----------------------------------------------------------------------------------------------------------------------------------------------
	bool doctor::readObject3(string fileName, string username) //Function for reading username and password
	{
		doctor temp;
		ifstream doctor_file(fileName, ios::binary);
		while (doctor_file.read((char*)&temp, sizeof(doctor))) {
			if (temp.get_username() == username.c_str()) {   //condition to match username and password from file
				doctor_file.close();
				return true;
			}
		}                                                                                
		return false;
	}
	bool doctor ::readObject4(string fileName, string cnic)
	{
		doctor temp;
		ifstream doctor_file(fileName, ios::binary);
		while (doctor_file.read((char*)&temp, sizeof(doctor))) {
			if (temp.get_Dcnic() == cnic.c_str()) {   //condition to match username and password from file
				doctor_file.close();
				return true;
			}
	      }
		return false;
	}
	//-------------------------------------------------------------------------------------------------------------------------------------------
	bool doctor::readObject(string fileName, string username, string password) //Function for reading username and password
	{
		doctor temp;
		ifstream doctor_file(fileName, ios::binary);
		while (doctor_file.read((char*)&temp, sizeof(doctor))) {
			if (temp.get_username() == username.c_str() && temp.get_password() == password.c_str()) {   //condition to match username and password from file
				doctor_file.close();
				return true;
			}
		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------
	void doctor::readObject2(string fileName, string speciality) //Function for reading username and password
	{
		doctor temp;
		ifstream doctor_file2(fileName, ios::binary);
		while (doctor_file2.read((char*)this, sizeof(doctor))) {
			if (temp.get_specialty() == speciality.c_str()) {   //condition to match username and password from file
				doctor_file2.close();	
			}
		}
	}
//---------------------------------------------------------------------------------------------------------------------------------------------------
	void  switcher_pp()
	{
		int y;doctor dl;
		cin >> y;
		switch (y)
		{
		case 1:
		{dl.register_him();
		break;
		}
		case 2:                               //switcher app for the doctor
		{
			dl.edit_doctor();
			break;
		}
		case 3:
		{
			dl.get_appoint_data();
			break;
		}
		}

	}
	//------------------------------------------------------------------------------------------------------------------------------------------------

	void doctor :: login()
	{
		bool a;
		string username, password;
		cout << " Enter your Email :"; cin >> username;
		cout << endl;
		cout << " Enter your Passwrod :"; cin >> password;
		a = readObject(doctor_filename, username,password);           //check for login whether user give true input or not
		if (a == true)
		{
			cout << " You are logined Now" << endl; 
			cout << endl;
			char c;
			do {

				cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
				checkpass::doctor_menu();  //function for displaying menu of admin
				switcher_pp();
				cout << " ---------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << " If You want to process the function further press Y else N" << endl;
				cin >> c;
			
			doctor temp1;
			cout << "if you want to see appointments press Y else N " << endl;
			char s;
			cin >> s;
			appointment qwe;
			string b;
			switch (s)
			{
			case 'Y':
			{
				appointment temp;
				fstream myfile(appointment_file, ios::in | ios::out | ios::binary);
				while (myfile.read((char*)&temp, sizeof(appointment)))
				{
					if (strcmp(this->cnic , temp.get_doccnic().c_str()))
					{
						cout << " if you want to approve Press 1 else 2 " << endl;
						int jk;cin >> jk;
						switch (jk)
						{
							
						case 1:
						{appointment val;
						fstream filen(appointment_file,  ios:: in | ios:: out | ios:: binary );
							while (filen.read((char*)&val, sizeof(appointment)))
							{
								if (strcmp(this->cnic, val.get_doccnic().c_str()))
								{
									b = "Approve";
									val.set_appointstatus(b);
									cout << "Appointment is approved " << endl;
			                        
									int current = myfile.tellg();
									int oneblock = sizeof(val);
									myfile.seekg(current - oneblock);
									myfile.write((char*)&val, sizeof(val));
									myfile.close();
									//----------------------------------------------------
									appointment app3;doctor logo;
									ifstream gumfile(appointment_file, ios::binary);
									while (gumfile.read((char*)&app3, sizeof(appointment)))
									{
										string df = "Approve";
										if (app3.appoint_status == df.c_str())
										{
											for (int i = 0;i < 5;i++)
											{
												logo.slot_array[i] == false;
											}
										}
										gumfile.close();
										break;
									}
								
								}
								
							}
							break;
						}
						case 2:
						{
							appointment val;
						fstream filen(appointment_file, ios::in | ios::out | ios::binary);
							while (filen.read((char*)&val, sizeof(appointment)))
							{
								if (strcmp(this->cnic, val.get_doccnic().c_str()))
								{
									b = "Not accepted";
									val.set_appointstatus(b);
									cout << "Appointment is approved " << endl;
									int current = myfile.tellg();
									int oneblock = sizeof(val);
									myfile.seekg(current - oneblock);
									myfile.write((char*)&val, sizeof(val));
									myfile.close();
								}
							}
						
							break;
						}
						}
					}
					else {
						cout << " NO appointment is pending " << endl;
					}
					myfile.close();
					break;
					int current = myfile.tellg();
					int oneblock = sizeof(temp);
					myfile.seekg(current - oneblock);
					myfile.write((char*)&temp, sizeof(temp));
					myfile.close();
				}
				break;
			}
			case'N': {
				cout << "     " << endl;
				break;
			}
			}
			} while (c == 'Y');
		}
		else if (a == false)
		{
			cout << " not logined please register your account " << endl;
		register_iss2::register_issue();
		}
	}
	//------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------
	double doctor::get_charges(string c)
	{
		doctor temp;
		ifstream doctor_file(doctor_filename, ios::binary);
		while (doctor_file.read((char*)&temp, sizeof(doctor))) {
			if (strcmp(temp.get_specialty().c_str(), c.c_str()))
			{   //condition to match username and password from file
				return 	this->charges;
				doctor_file.close();                                           
			}
			else cout << " No speciality match " << endl;
		}
		
	
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------
	void doctor::register_him()     //Register  function  for Doctor
	{
		string name;int id;string cnic;long int contact;string p, cp;bool dfc;bool check;bool pass_check;bool check2;bool check3, check4;string usn;
		doctor temp;bool ghol;bool hum;
		cout << "                                               Enter your information : " << endl;
		do {
			cout << " Enter your Email for the Account :  ";
			cin >> usn;
			this->set_username(usn);
			ghol = readObject3(doctor_filename, usn);
			if (ghol == true)
			{
				cout << " Enter another Email, it is already taken " << endl;
			}
		} while (ghol == true);
		do {
			do {
				cout << " Enter your cnic :  ";
				cin >> cnic;
				dfc = this->set_cnic(cnic);
			hum=	readObject3(doctor_filename, cnic);
			if (hum == true)
			{
				cout << " Already taken " << endl;
			}
			} while (hum == true);
			if (dfc == false)
			{
				cout << " Invalid cnic" << endl;
			}
		} while (dfc == false);
		if (dfc = true)
		{
			cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
			do {
				//---------------------------------------------------condition for password 8 digit and password conditions-----------------------------------------------------	
				do {
					do {
						cout << " Set Your Password : which include number,lower, upper and special character and consistes 8 digit :" << endl;
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
                            cout << " Enter Again " << endl;
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
							cout << " Enter Again, " << endl;
							cout << endl;
						}
						if (p != cp)
						{
							cout << " Your password is incorrect please Enter again" << endl;
						}
					} while (check2 == false);
					//----------------------------------------------------------------------------------------------------------------------------------------------
				} while (p != cp);
				check = readObject(doctor_filename, usn, cp);
				if (check == true)
				{
					cout << " Sorry You have already Registered " << endl;
					cout << endl;
				}
				else if (check == false)
				{
					cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
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
					int ex;string area, hp,hour,city;
					cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << endl;
					cout << " Enter your Year of experience :";
					cin >> ex;
					this->experience = ex;
					cout << "Enter your specialization Area :";
					cin >> area;
					strcpy_s(this->specialization, area.c_str());
					cout << "Enter the qualification of doctor :";
					ifstream myjk(doctor_filename, ios::binary);
					string a1 = "dermatologist";
					if (area == "dermatologist")
					{
						dermatologist der;
						doctor* v = &der;
						v->edu_of_doc();
					}
					else if (area == "oncologist")
					{
						oncologist 	ono;
						doctor* val = &ono;
						val->edu_of_doc();
					}
					else if (area == "gynecologist")
					{
						gynecologist 	ono;
						doctor* val = &ono;
						val->edu_of_doc();
					}
					else if (area == "orthopedic")
					{
						orthopedic 	ono;
						doctor* val = &ono;
						val->edu_of_doc();
					}
					cout << " Enter your Charges :" << endl;
				double charge;
					cin >> charge;
					this->charges = charge;
							cout << "Enter the location of clinic :";
					string val;
					cin >> val;
					strcpy_s(this->location, val.c_str());
					cout << "Enter the name of Hospital :";
					cin >> hp;
					strcpy_s(this->hospital_name, hp.c_str());
					cout << "Enter your availability time :";
					cin >> hour;
					strcpy_s(this->avail_hour, hour.c_str());
					cout << "Enter the name of your city :";
					cin >> city;

					strcpy_s(this->city_name, city.c_str());
					for (int i = 0;i < 7;i++)
					{
						this->slot_array[i] = false;
					}
					int y;
					cout << " Enter the number of days :";
					cin >> y;
					this->day_num = y;
					this->days = new string[y];
					string val5;
					for (int i = 0;i < y;i++)
					{
						cin >> val5;
						cout << endl;
						this->days[i] = val5;
					}
				
						     write_object();
				}
			}
		}
	//------------------------------------------------------------------------------------------------------------------------------------------------
		void doctor::add_money(double val)
		{
			this->money = val;
  }
	//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
		string doctor::availiability_time()
		{
			return this->avail_hour;
		}
		//-------------------------------------------------------------------------------------------------------------------------------------------------------
				void doctor :: write_object()
				{
					ofstream myFile(doctor_filename, ios::binary | ios::app);
		if (myFile.write((char*)this, sizeof(doctor))) {
			cout << " Congrats Your Data is updated " << endl;
			myFile.close();                                         //Function for to insert object 
		}
		else {
			cout << "Failed! Data was not entered, Please Enter again." << endl;
		}
	}
//--------------------------------------------------------------------------------------------------------------------------------------------- 
				void doctor::admin_funfornewadd(string jk)
				{
					doctor temp;
					fstream myFile(doctor_filename, ios::in | ios::out | ios::binary);
					while (myFile.read((char*)&temp, sizeof(temp))) {
						if (temp.get_Dcnic() == jk.c_str()) {
							int ex;string area, hp, hour, city;
							cout << " Change year of experience of respective doctor :";
							cin >> ex;
							temp.experience = ex;
							cout << "Change specialization Area of doctor: ";
							cin >> area;
							strcpy_s(temp.specialization, area.c_str());
							cout << "Change the name of Hospital :";                          //update of the data
							cin >> hp;
							strcpy_s(temp.hospital_name, hp.c_str());
							cout << "Change availability time of doctor:";
							cin >> hour;
							strcpy_s(temp.avail_hour, hour.c_str());
							cout << "Change the name of city of doctor :";
							cin >> city;
							strcpy_s(temp.city_name, city.c_str());
							int current = myFile.tellg();
							int oneblock = sizeof(temp);
							myFile.seekg(current - oneblock);
							myFile.write((char*)&temp, sizeof(temp));
							cout << "Success! Name Updated." << endl;
							myFile.close();
						}
					}
						  }
				//--------------------------------------------------------------------------------------------------------------------------------

	void doctor::delete_doctor(int id) {
		doctor count;
		string doctor_filename_temp = "Doctor_list.dat";

		fstream myFile(doctor_filename, ios::in | ios::out | ios::binary);
		ofstream myFile_write(doctor_filename_temp, ios::app | ios::binary);
		while (myFile.read((char*)&count, sizeof(doctor))) {
			if (count.get_id() != id) {
				myFile_write.write((char*)&count, sizeof(doctor));
			}                                                        // Delete function for the deletion of Doctor on the base of id
			else {
				cout << "Success! Object Deleted." << endl;
			}
		}
		myFile.close();
		myFile_write.close();
		remove(doctor_filename.c_str());
		rename(doctor_filename_temp.c_str(), doctor_filename.c_str());
	}
//-------------------------------------------------------------------------------------------------------------------------------------------------
string doctor::get_Dcnic()
	{
		return this->cnic;
}
	//-----------------------------------------------------------------------------------------------------------------------------------------------
string doctor::get_area()
{
	return this->location;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
string doctor::get_hopital_name()
{
	return this->hospital_name;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
string doctor::get_specialty()
{
	return this->specialization;
}
//===============================================================================================================================================
	void doctor :: doc_dis_BF(int uniqueIndex) {
		doctor temp;
		ifstream myFile(doctor_filename, ios::binary);
		while (myFile.read((char*)&temp, sizeof(doctor))) {
			if (temp.get_id() == uniqueIndex) {                             //display function for doctor on the base of entered id
				temp.display_doctor();
			}
			else { cout << "Doctor was not found of this id" << endl; }
				myFile.close();
				//*this = temp;
			}
		}
//----------------------------------------------------------------------------------------------------------------------------------------------------
	void doctor::availability(string cnic)
	{
		char y;
		string num;
		doctor temp;
		ifstream myFile(doctor_filename, ios::binary);
		while(myFile.read((char*)&temp,sizeof(temp)))
		{ 
			if (temp.get_Dcnic() == cnic)
			{
				cout << " Enter the new availiabilty hours " << endl;
				cin >> num;
				strcpy_s(this->avail_hour, num.c_str());
			}
			else cout << "We cannot respective doctor " << endl;
			myFile.close();
		}

	}
	//------------------------------------------------------------------------------------------------------------------------------------------------
	void doctor ::edit_doctor()
	{
		cout << " Enter the name:";
		string name;
		cin >> name;
		strcpy_s(this->name, name.c_str());
		cout << " Enter the id :";
		int id;cin >> id;
		this->id = id;
		cout << " Enter the cnic ";
		string cnic;
		cin >> cnic;                                           //edition of the doctor
		strcpy_s(this->cnic, cnic.c_str());
		cout << " Enter the charges :";
		double charges;cin >> charges;
		this->charges = charges;

		cout << " Enter the hospital name :";
		string hp;cin >> hp;
		strcpy_s(this->hospital_name, hp.c_str());
		cout << "Enter the experience :";
		int ex;
		cin >> ex;
		this->experience = ex;
	}
	void doctor:: get_appoint_data()
	{
		appointment a;
		ifstream myfile(appointment_file, ios::binary);
		while (myfile.read((char*)&a, sizeof(appointment)))
		{
			if (a.doc_cnic == this->cnic)
			{
				for (int i = 0;i < 35;i++)
					cout << this->app->appoint_status[i];
			}
		}
	}
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	
	void doctor ::fun(appointment*a)
	{
		app = a;
		
	}
	//-----------------------------------------------------------------------------------------------------------------------------------------------------
	