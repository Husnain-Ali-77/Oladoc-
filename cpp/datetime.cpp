#include "datetime.h"
datetime::datetime()
{

}
datetime::datetime(string a,string b)
{
	strcpy_s(this->day_appoint, a.c_str());
	strcpy_s(this->time, b.c_str());
}
