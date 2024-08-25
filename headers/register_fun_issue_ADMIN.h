#pragma once
#include"admin.h"
#include<iostream>
using namespace std;
admin admin_data1;
class register_iss {
public:
	static void register_issue_a()
	{
		char num;
		cout << "  if you want to register  press Y else N  " << endl;
		cout << endl;
		cin >> num;
		switch (num)
		{
		case 'Y': {
			admin_data1.register_him();
			break;
		}
		case 'N':
		{
			cout << "               " << endl;
		}
		}
	}
};