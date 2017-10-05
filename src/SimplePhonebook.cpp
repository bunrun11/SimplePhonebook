#include <iostream>
#include <fstream>
#include <sstream>
#include "Phonebook.h"
using namespace std;

void AddEntry(Phonebook&);
void Search(Phonebook&);
void DeleteEntry(Phonebook&);
void PrintList(Phonebook&);
bool ValidateName(string, string);
bool ValidateNumber(string);

int main() {

	Phonebook phonebook;
	phonebook.ReadFile("phonebook.txt");

	cout<<"***MY PHONEBOOK APPLICATION***"<<endl;
	cout<<"Please choose an operation:"<<endl;
	char input;
	do
	{
		cout<<"A(Add)|S(Search)|D(Delete)|L(List)|Q(Quit): ";
		cin>>input;

		switch(input){
		case 'A':
			AddEntry(phonebook);
			break;

		case 'S':
			Search(phonebook);
			break;

		case 'D':
			DeleteEntry(phonebook);
			break;

		case 'L':
			PrintList(phonebook);
			break;
		}

		cout<<endl;
	}
	while(input != 'Q');

	//cout<<phonebook<<endl;

	return 0;
}

void AddEntry(Phonebook &phonebook){
	string firstname, lastname;
	cout<<"Enter name: ";
	cin>>firstname>>lastname;

	if(ValidateName(firstname, lastname)){
		string phonenumber;
		cout<<"Enter phone: ";
		cin>>phonenumber;

		if(ValidateNumber(phonenumber)){
			phonebook.Add(firstname, lastname, phonenumber);
			return;
		}
	}
	cout<<"Error"<<endl;
}

void Search(Phonebook &phonebook){
	string firstname, lastname;
	cout<<"Enter name: ";
	cin>>firstname>>lastname;
	cout<<"Phone Number: "<<phonebook.Find(firstname, lastname)<<endl;
}

void DeleteEntry(Phonebook &phonebook){
	string firstname, lastname;
	cout<<"Enter name: ";
	cin>>firstname>>lastname;
	phonebook.Delete(firstname, lastname);

}

void PrintList(Phonebook &phonebook){
	phonebook.Print();
}

bool ValidateName(string firstname, string lastname){
	return true;
}

bool ValidateNumber(string number){
	return true;
}
