#include "video_consultation.h"

video_consultation::video_consultation()
{

}
video_consultation::video_consultation(string name, string cnic, string pat_nam, string pat_cnic, string a, string b, double val) :
	appointment(name, cnic, pat_nam, pat_cnic, a, b)
{
	this->charges_video = val;
}