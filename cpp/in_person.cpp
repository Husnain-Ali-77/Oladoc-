#include "in_person.h"
in_person::in_person()
{

}
in_person::in_person( string name, string cnic, string pat_nam, string pat_cnic, string a, string b, double val):appointment(name,cnic,pat_nam,pat_cnic,a,b)
{
	string v;
	v = "pending";
	strcpy_s(this->appoint_status, v.c_str());
	this->charges = val;
}