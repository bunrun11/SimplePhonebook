#include <iostream>
#include <fstream>
#include <sstream>
#include "Phonebook.h"
using namespace std;

void AddEntry(Phonebook&);
void Search(Phonebook&);
void DeleteEntry(Phonebook&);
void PrintList(Phonebook&);
bool ValidateName(string);
bool ValidateNumber(string);

int main() {

	Phonebook phonebook;
	phonebook.ReadFile("phonebook.txt");

	cout<<"***MY PHONEBOOK APPLICATION***"<<endl;
	cout<<"Please choose an operation:"<<endl;
	string input;
	do
	{
		cout<<"A(Add)|S(Search)|D(Delete)|L(List)|Q(Quit): ";
		getline(cin, input);

		switch(input[0]){
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
	while(input[0] != 'Q');

	return 0;
}

void AddEntry(Phonebook &phonebook){
	string name = "";
	cout<<"Enter name: ";
	getline(cin, name);
	if(name[name.length()-1] == '\r' || name[name.length()-1] == '\n'){
		name.erase(name.length()-1); // remove \r or \n
	}

	if(ValidateName(name)){
		string number;
		cout<<"Enter phone: ";
		getline(cin, number);
		if(number[number.length()-1] == '\r' || number[number.length()-1] == '\n'){
				number.erase(number.length()-1); // remove \r or \n
			}

		if(ValidateNumber(number)){
			phonebook.Add(name + " " + number);
			return;
		}
	}
	cout<<"Error"<<endl;
}

void Search(Phonebook &phonebook){
	string name = "";
	cout<<"Enter name: ";
	getline(cin, name, '\n');
	if(name[name.length()-1] == '\r' || name[name.length()-1] == '\n'){
			name.erase(name.length()-1); // remove \r or \n
		}
	cout<<"Phone Number: "<<phonebook.Find(name)<<endl;
}

void DeleteEntry(Phonebook &phonebook){
	string name = "";
	cout<<"Enter name: ";
	getline(cin, name, '\n');
	if(name[name.length()-1] == '\r' || name[name.length()-1] == '\n'){
			name.erase(name.length()-1); // remove \r or \n
		}
	phonebook.Delete(name);

}

void PrintList(Phonebook &phonebook){
	phonebook.Print();
}

bool ValidateName(string name){
	return true;
}

bool ValidateNumber(string number){
	return true;
}
