#pragma once
#include"payment.h"
class e_transaction:public payment
{
public:
	void send_money(double);
};

