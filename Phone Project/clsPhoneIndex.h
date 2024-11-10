#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include"clsPerson.h"

using namespace std;

class clsPhoneIndex
 {
 private:
	 vector<clsPerson>vPhone;
 public:

	 int disPlayMainMenue();
	 void AddPerson();
	 void RemovePerson();
	 void FindPerson();
	 void ChangePerson();
	 void DisplayAllPerson();
	 void RepeatPrinting();
	 void StoreDataFromVectorToFile();
 
};

