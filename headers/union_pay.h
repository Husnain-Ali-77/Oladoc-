#pragma once
#include"bank_transfer.h"
class union_pay :public bank_transfer
{
public:
	void send_money(double);
};

