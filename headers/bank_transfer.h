#pragma once
#include"payment.h"
class bank_transfer : public payment
{


public:
	void send_money( double );
};

