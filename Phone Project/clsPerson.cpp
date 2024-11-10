#include "clsPerson.h"

clsPerson::clsPerson(string Name , string Phone)
{
	this->Name = Name;
	this->Phone = Phone;
}
void clsPerson::setName(string Name)
{
	this->Name = Name;
}
string clsPerson::GetName()
{
	return Name;
}
void clsPerson::setPhone(string Phone)
{
	this->Phone = Phone;
}
string clsPerson::GetPhone()
{
	return Phone;
}