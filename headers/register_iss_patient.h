#pragma once
#include"patient.h"
#include<iostream>
#include<string>
using namespace std;
patient patient_data1;
class register_iss1 {
public:
	static void register_issue_p()
	{
		char num;
		cout << "  if you want to register  press Y else N  " << endl;
		cout << endl;
		cin >> num;
		switch (num)
		{
		case 'Y': {
			patient_data1.register_him();
			break;
		}
		case 'N':
		{
			cout << "               " << endl;
		}
		}
		
	}
	
	
	
};