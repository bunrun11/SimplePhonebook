/*
 * Phonebook.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: jobbe_000
 */

#include "Phonebook.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



Phonebook::Contact::Contact(){}
Phonebook::Contact::Contact(string entry){
	Set(entry);
}

string Phonebook::Contact::GetName(){
	return firstname + " " + lastname;
}

void Phonebook::Contact::Set(string entry){
	stringstream stream(entry);
	getline(stream, firstname, ' ');
	getline(stream, lastname, ' ');
	getline(stream, phone, ' ');
}

string Phonebook::Contact::toString(){
	return firstname+" "+lastname+" "+phone;
}

bool Phonebook::Contact::operator==(Contact other){
	return this->toString() == other.toString();
}

//ostream& Phonebook::Contact::operator<<(ostream& os, const Contact entry){
//	os<<entry.toString();
//	return os;
//}

Phonebook::Phonebook(){
	count = 0;
	maxSize = 5;
	addresses = new Contact[5];
}

Phonebook::Phonebook(string _arr[], int _size){
	count = 0;
	maxSize = 5;
	addresses = new Contact[5];
}

Phonebook::~Phonebook()
{
	//cout<<"Delete Phonebook"<<endl;
	delete[] addresses;
}

int Phonebook::GetSize(){
	return count;
}

string Phonebook::Find(string name){
	for(int i = 0; i < count; i++){
		Contact &person = addresses[i];
		if(person.firstname + " " + person.lastname == name){
			return person.phone;
		}
	}
	return "";
}

void Phonebook::Add(string entry){
	if(count >= maxSize){
		ExpandArray();
	}
	addresses[count].Set(entry);
	count++;
}

void Phonebook::ReadFile(string filename){
	ifstream filestream;
	filestream.open(filename);
	string entry;
	while(!filestream.eof()){
		getline(filestream, entry, '\n');
		Add(entry);
	}
	filestream.close();
}

void Phonebook::Delete(string fullname){
	bool isFound = false;
	for(int i = 0; i < count; i++)	{
		if(isFound){
			addresses[i-1] = addresses[i];
		}
		else if(addresses[i].GetName() == fullname){
			isFound = true;
		}
	}

	if(isFound){
		count--;
	}
	//delete temp;
}

void Phonebook::ExpandArray(){
	Contact* newArr = new Contact[maxSize*2];
	for(int i = 0; i < count; i++)
	{
		newArr[i] = addresses[i];
	}

	delete[] addresses;
	addresses = newArr;
	maxSize *= 2;
}

void Phonebook::Print(){
	cout<<"------Phonebook------"<<endl;;
	for(int i = 0; i < count; i++)
	{
		cout<<addresses[i].toString()<<endl;
	}
	cout<<"-----------------------"<<endl;;
}

