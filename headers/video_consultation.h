#pragma once
#include"appointment.h"
class video_consultation :public appointment
{
private:
	double charges_video;
public:
	video_consultation();
	video_consultation(string name, string cnic, string pat_nanm, string pat_cnic, string a, string b, double val);
};

