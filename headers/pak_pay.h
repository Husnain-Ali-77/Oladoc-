#pragma once
#include"bank_transfer.h"
class pak_pay : public bank_transfer
{
public:
	virtual void send_money(double);
};

