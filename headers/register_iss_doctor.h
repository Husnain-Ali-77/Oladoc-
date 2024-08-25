#pragma once
#include"doctor.h"
#include<iostream>
using namespace std;
doctor doctor_data1;
class register_iss2 {
public:
	//static string* str;
	/*static int a;*/
	static void register_issue()
	{
		char num;
		cout << "  if you want to register  press Y else N  " << endl;
		cout << endl;
		cin >> num;
		switch (num)
		{
		case 'Y': {
			doctor_data1.register_him();
			break;
		}
		case 'N':
		{
			cout << "               " << endl;
		}
		}
	}
	//static void display_days()
	//{
	//	int y;		
	//	cout << " Enter the number of days :";
	//	cin >> y;
	//	a = y;
	//	string* str;
	//	str = new string[a];
	//	//string* str= new string[y];
	//	string add;
	//	str = new string[y];
	//	for (int i = 0;i < y;i++)
	//	{
	//		cin >> add;
	//		str[i] = add;
	//		cout << endl;
	//	}
	//}/*	static void display2_docday()
	//{
	//	for (int i = 0;i < a;i++)
	//	{
	//		cout << str[i] << endl;
	//	}
	//}*/
};
//int register_iss2::a = 0;
//string register_iss2 ::* str[];