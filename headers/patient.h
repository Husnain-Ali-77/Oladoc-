#pragma once
#include"User.h"
#include<fstream>
#include"doctor.h"
#include"appointment.h"
#include"helper_file_variables.h"
#include"helper_functions.h"
#include"payment.h"
#include"patient.h"
#include"feedback.h"
class patient :public User
	{
	private:
		int day;
		int balance;
		bool appoint_status;
		
	public:
		char appoint_s[30];
		patient();
		patient(string name, int id, string cnic, long int contact_num, string password, string user_name, string con_pass,int bb,bool);
		void login();
		void set_balance(int s);
	string get_Pname();
	string get_Pcnic();
	int get_patientday();
		void register_him();
		void reset_password(string new_password,string);
		void FH_insertObject();
		void update_appoint(string);
		void update_profile();
		bool readObject(string fileName, string username, string password);
		 void dis_pat_data(string );
		void pat_dis_BFH(int);
		int get_patbalance();
		void get_appo_status();
		void ser_appo();
		void search_doctor(string specialty);

	};


