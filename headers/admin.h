#pragma once
#include<fstream>
#include"helper_file_variables.h"
#include"doctor.h"
#include"patient.h"
#include"User.h"
class admin :public User
{
	appointment* appointment;

	public:
		admin();
		admin(string name, int id,string cnic, long int contact_num, string password, string user_name, string con_pass);
		bool readObject(string fileName, string username, string password);
		void login();
		void register_him();
		void FH_insertObject();
		void switches_admin();
	};

