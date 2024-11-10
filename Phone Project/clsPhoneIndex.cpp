#include "clsPhoneIndex.h"

int clsPhoneIndex::disPlayMainMenue()
{
	system("cls");
	cout << "\t\t\t Phone Project\n";
	cout << "\t\t\t -------------\n\n";
	cout << "1 -> Add Persons\n";
	cout << "2 -> Remove Persons\n";
	cout << "3 -> Find Persons\n";
	cout << "4 -> Change Persons Data\n";
	cout << "5 -> Display All Persons\n";
	cout << "6 -> Store Data To File\n";
	cout << "7 -> Exit\n";
	int chioce;
	cout << "Please Enter Choice: ";
	cin >> chioce;

	return chioce;
}
void clsPhoneIndex::AddPerson()
{
	system("cls");
	cout << "\t\t\tAdd Person Menu" << endl;
	cout << "\t\t\t---------------" << endl;
	string Name;
	cout << "Please enter Name : ";
	cin.ignore();
	getline(cin, Name);
	string Phone;
	cout << "Please enter Phone: ";
	getline(cin, Phone);

	clsPerson Person1(Name, Phone);

	vPhone.push_back(Person1);

	cout << "Press any key to continue: ";
	cin.ignore();
}
void clsPhoneIndex::RepeatPrinting()
{
	system("cls");
	cout << "------------------------------------------\n";
	cout << "ID  " << "Name                     " << "Phone                    " << "\n";
	cout << "--  " << "----                     " << "-----                    " << "\n";
	cin.ignore();
	for (int i = 0; i < vPhone.size(); i++)
	{
		/*
		// setw ==> this function allcoated spaces which are you need after that writing do from right to left
		// sammery this function By default is strat from right to lsft and writen the text
		//cout << right;
		*/

		cout << left; // do opposite ==> [setw function]
		cout << setw(4) << i + 1;
		cout << setw(25) << vPhone[i].GetName();
		cout << setw(25) << vPhone[i].GetPhone() << "\n";
	}
	cout << "------------------------------------------\n";
}
void clsPhoneIndex::DisplayAllPerson()
{
	RepeatPrinting();

	cout << "Press any key to continue: ";
	cin.ignore();
}
void clsPhoneIndex::RemovePerson()
{
	RepeatPrinting();

	int num;
	cout << "Please Enter Number Person: ";
	cin >> num;
	while (num < 1 || num > vPhone.size()) {
		cout << "Please Enter Number In Range: ";
		cin >> num;
	}

	vPhone.erase(vPhone.begin() + (num - 1));// -1 ==> index start from 0

	cout << "Press any key to continue: ";
	cin.ignore();
}
void clsPhoneIndex::ChangePerson()
{
	RepeatPrinting();

	int  n;
	cout << "Enter Number Person to Change: ";
	cin >> n;

	string Name;
	cout << "\nOld Name is: [" << vPhone[n - 1].GetName() << "].\n";
	cout << "Please Enter a New Name: ";
	cin.ignore();
	getline(cin, Name);

	string Phone;
	cout << "\nOld Phone is: [" << vPhone[n - 1].GetPhone() << "].\n";
	cout << "Please Enter a New Phone: ";
	cin.ignore();
	getline(cin, Phone);

	clsPerson Person1(Name, Phone);

	vPhone.erase(vPhone.begin() + (n - 1));// -1 ==> index start from 0
	vPhone.insert(vPhone.begin() + (n - 1), Person1);

	cout << "Press any key to continue: ";
	cin.ignore();
}
void clsPhoneIndex::FindPerson()
{
	system("cls");
	string Name;
	cout << "Please Enter Name Person To Find: ";
	cin.ignore();
	getline(cin, Name);
	cout << "------------------------------------------\n";
	cout << "ID  " << "Name                     " << "Phone                    " << "\n";
	cout << "--  " << "----                     " << "-----                    " << "\n";
	for (int i = 0; i < vPhone.size(); i++)
	{
		clsPerson Person1 = vPhone[i];
		if (Person1.GetName().find(Name) != std::string::npos)
		{
			cout << left;
			cout << setw(4) << i + 1;
			cout << setw(25) << Person1.GetName();
			cout << setw(25) << Person1.GetPhone() << "\n";
		}
	}
	cout << "------------------------------------------\n";
	cout << "Press any key to continue: ";
	cin.ignore();

}
void clsPhoneIndex::StoreDataFromVectorToFile()
{
	system("cls");
	string FileName = "";
	cout << "Please Enter What Name File Which Want To Store Data:\n"
		<< "[Note File Must be.txt]:  ";

	cin.ignore();
	getline(cin, FileName);
	int counter = 1;
	fstream MyFile;
	MyFile.open(FileName, ios::app | ios::out); // can Remove one mode and still only one
	if (MyFile.is_open())
	{
		MyFile << "ID  " << "Name                     " << "Phone                    " << "\n";
		MyFile << "--  " << "----                     " << "-----                    " << "\n";
		for (clsPerson& DataPerson : vPhone)
		{
			MyFile << left;
			MyFile << setw(4) << counter;
			MyFile << setw(25) << DataPerson.GetName();
			MyFile << setw(25) << DataPerson.GetPhone() << endl;
			counter++;
		}
		MyFile.close();
	}

	cout << "\nPress any key to continue:\n";
	cin.ignore();
}
