#include <iostream>
#include"clsPerson.h"
#include"clsPhoneIndex.h"
using namespace std;
int main()
{
	clsPhoneIndex Phone1;
	int choice;
	do
	{
		choice = Phone1.disPlayMainMenue();

		switch (choice)
		{
		case 1:
			Phone1.AddPerson();
			break;
		case 2:
			Phone1.RemovePerson();
			break;
		case 3:
			Phone1.FindPerson();
			break;
		case 4:
			Phone1.ChangePerson();
			break;
		case 5:
			Phone1.DisplayAllPerson();
			break;
		case 6:
			Phone1.StoreDataFromVectorToFile();
			break;
		case 7:
			system("cls");
			cout << "\nThanks ..:)\n";
			break;
		default:
			cin.ignore();
			cout << "Error choice!!" << endl;
			cout << "Press any key to continue:  ";
			cin.ignore();
		}
	} while (choice != 7);

	system("pause>0");
	return 0;
}