#pragma once
#include<iostream>
using namespace std;
class clsPerson
{
private:
	string Name;
	string Phone;

public:
	
	clsPerson(string Name, string Phone);
	void setName(string Name);
	string GetName();
	void setPhone(string Phone);
	string GetPhone();
};