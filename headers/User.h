#pragma once
#include<iostream>
#include"helper_file_variables.h"
#include"helper_functions.h"
using namespace std;
class User
{
	protected:
		char name[25];
		int id;
		char cnic[14];
		long long  int contact_num;
		char password[9];
		char user_name[25];
		char conf_pass[25];
	public:
		User();
		User(string name, int id, string cnic, long long  int contact_num, string password, string user_name, string con_pass);
		void set_name(string name);
		virtual void login();
		void set_id(int id);
		void set_cont_num(long int id);
		bool set_cnic(string cnic);
		bool set_pass(string pass);
		bool confirm_pass(string pass);
		void set_username(string username);
		int get_id();
		string get_username();
		string get_password();
};

