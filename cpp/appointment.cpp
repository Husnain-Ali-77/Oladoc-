#include "appointment.h"

appointment::appointment()
{
	string v;
	v = "pending";
	strcpy_s(this->appoint_status, v.c_str());
}
appointment::appointment(string doc_n, string doc_c, string pa_nam, string pat_cn,string a,string b)//:obj(a,b)
{
	string v;
	v = "pending";
	strcpy_s(this->appoint_status, v.c_str());
	strcpy_s(this->doc_name, doc_n.c_str());
    strcpy_s(this->doc_cnic, doc_c.c_str());
	strcpy_s(this->pat_name, pa_nam.c_str());
	strcpy_s(this->pat_cnic, pat_cn.c_str());
}
void appointment::write_appointfile()
{
	//appointment app;
	ofstream filenum(appointment_file, ios::binary | ios::app);
	if(filenum.write((char*)this, sizeof(appointment)))
	{
	cout << " Congrats Your Data is updated " << endl;
	filenum.close();                                         //Function for to insert object 
		}
		else {
			cout << "Failed! Data was not entered, Please Enter again." << endl;
		}
}
void appointment::funwriteforappoint(string a,string b,string c,string d)
{
	strcpy_s(this->doc_name, strlen(d.c_str()) + 1, d.c_str());
	strcpy_s(this->doc_cnic, strlen(c.c_str()) + 1, c.c_str());
	strcpy_s(this->pat_name, strlen(a.c_str()) + 1, a.c_str());
	strcpy_s(this->pat_cnic, strlen(b.c_str()) + 1, b.c_str());
}
void appointment::set_appointstatus(string v)
{
	strcpy_s(this->appoint_status, v.c_str());
}
string appointment ::get_doccnic()
{
	return this->doc_name;
}
string appointment::get_patcnic()
{
	return this->pat_cnic;
}
void appointment::set_date()
{
	int y;
	cout << "Enter the date :";
	cin >> y;
	this->date = y;
}