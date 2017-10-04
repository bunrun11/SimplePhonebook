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
	phonebook.ReadFile("fakephonebook.txt");

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
	cout<<"Name: ";
	getline(cin, name);
	name.erase(name.length()-1); // remove \r

	if(ValidateName(name)){
		string number;
		cout<<"Number: ";
		getline(cin, number);
		number.erase(number.length()-1); // remove \r

		if(ValidateNumber(number)){
			phonebook.Add(name + " " + number);
			return;
		}
	}
	cout<<"Error"<<endl;
}

void Search(Phonebook &phonebook){
	string name = "";
	getline(cin, name, '\n');
	name.erase(name.length()-1); //remove \r
	cout<<phonebook.Find(name)<<endl;
}

void DeleteEntry(Phonebook &phonebook){
	string name = "";
	getline(cin, name, '\n');
	name.erase(name.length()-1); //remove \r
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
