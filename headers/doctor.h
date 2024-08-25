#pragma once
#include"User.h"
#include"helper_file_variables.h"
#include"appointment.h"
#include<fstream>
class doctor : public User
{
protected:
	double charges;
	char avail_hour[30];
	char city_name[30];
	char hospital_name[30];
	char specialization[30];
	int experience;
	char location[25];//area
	int patients_feedback;
	int day_num;
	double money;
	string * days;
	appointment* app;
	

public:
	bool slot_array[7];
	doctor();
	doctor(string name, int id, string cnic, long int contact_num, string password, string user_name, string con_pass,
		double charges, string avail_hour, string city, string hp, string slot, int experience, string location, int patient_feedback,int day);
		void login();
	void doc_dis_BF(int);
	void register_him();
	virtual void edu_of_doc();
	void readObject2(string fileName, string speciality);
	bool readObject3(string filename, string);
	void write_object();
	double get_charges(string);
	string get_Dname();
	string availiability_time();
	void admin_funfornewadd(string );
	string get_Dcnic();
	bool readObject4(string fileName, string );
	void fun(appointment* a);
	string get_hopital_name();
	void add_money(double);
	string get_area();
	void edit_doctor();
	void get_appoint_data();
	string get_specialty();
	bool readObject(string fileName, string username,string password);
	void delete_doctor(int id);
	void display_doctor();
	void availability(string cnic);
};
