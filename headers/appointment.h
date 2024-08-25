#pragma once
#include<iostream>
#include<fstream>
#include"helper_file_variables.h"
#include"datetime.h"
using namespace std;
class appointment
{
protected:
	
   
	//datetime obj;
public:
	 int date;
	 int slot_num;
	 char doc_name[30];
	 char doc_cnic[14];
	char pat_name[30];
	char pat_cnic[14];
	char appoint_status[35];
	appointment();
	appointment(string name, string cnic, string pat_nanm, string pat_cnic, string a, string b);
	void funwriteforappoint(string a,string b, string c, string d);
	void write_appointfile();
  	void set_appointstatus(string);
	string get_doccnic();
	string get_patcnic();
	void set_date();
};


//while (myfile.read((char*)this->app, sizeof(appointment)))
//{
//	if (this->app->get_doccnic() == this->cnic)
//	{
//		cout << " if you want to approve Press 1 else 2 " << endl;
//		int jk;cin >> jk;
//		switch (jk)
//		{
//		case 1:
//		{
//			b = "Approve";
//			app->set_appointstatus(b);
//			break;
//		}
//		case 2:
//		{
//			if (this->app->get_doccnic() == this->cnic)
//			{
//				b = "Not accepted";
//				app->set_appointstatus(b);
//
//			}
//			break;
//		}
//		}
//	}
//	else if (this->app->get_doccnic() != this->cnic)
//	{
//		cout << "You dont have any pending appointment " << endl;
//	}
//	myfile.close();
//}