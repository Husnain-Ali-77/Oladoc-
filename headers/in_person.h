#pragma once
#include"appointment.h"
class in_person :public appointment
{
private:
	double charges;
public:
	in_person();
	in_person(string name, string cnic, string pat_nanm, string pat_cnic, string a, string b,double val);
};
