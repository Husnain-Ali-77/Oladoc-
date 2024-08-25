#include "User.h"
	User::User()
	{

	}
	User::User(string name, int id, string cnic, long long int contact_num, string password, string user_name, string con_pass)
	{
		strcpy_s(this->name, name.c_str());
		strcpy_s(this->cnic, cnic.c_str());
		this->contact_num = contact_num;
		strcpy_s(this->password, password.c_str());
		strcpy_s(this->user_name, user_name.c_str());
		strcpy_s(this->conf_pass, con_pass.c_str());
	}
    void  User:: login()
	{

 }
	void User :: set_name(string name)
	{
		strcpy_s(this->name, name.c_str());
	}
	void User :: set_id(int id)
	{
		this->id = id;
	}
	void User :: set_cont_num(long int id)
	{
		this->contact_num = id;
	}
	bool User::set_cnic(string cnic)
	{
		int size = 0;
		for (int i = 0;cnic[i] != '\0';i++)
		{
			size++;
		}
		if (size == 13)
		{
			strcpy_s(this->cnic, cnic.c_str());
			return true;
		}
		else
			return false;
	}
	bool User ::set_pass(string pass)
	{
		int size = 0;
		for (int i = 0;pass[i] != '\0';i++)
		{
			size++;
		}
		if (size == 8)
		{
			strcpy_s(this->password, pass.c_str());
			return true;
		}
		else
			return false;
	}
	bool User :: confirm_pass(string pass)
	{
		int size = 0;
		for (int i = 0;pass[i] != '\0';i++)
		{
			size++;
		}
		if (size == 8)
		{
			strcpy_s(this->conf_pass, pass.c_str());
			return true;
		}
		else
			 false;
		
	}
	void User::set_username(string username)
	{
		strcpy_s(this->user_name, username.c_str());
	}
	string User :: get_username()
	{
		return this->user_name;
	}
	string User:: get_password()
	{
		return	this->password;
	}
	int User::get_id()
	{
		return this->id;
	}