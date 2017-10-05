/*
 * Phonebook.cpp
 *
 *  Created on: Oct 3, 2017
 *      Author: job
 */

#include "Phonebook.h"
#include <iostream>
#include <fstream>
using namespace std;

Phonebook::Contact::Contact(){}
Phonebook::Contact::Contact(string _firstname, string _lastname, string _phonenumber){
	Set(_firstname, _lastname, _phonenumber);
}

string Phonebook::Contact::GetName(){
	return firstname + " " + lastname;
}

void Phonebook::Contact::Set(string _firstname, string _lastname, string _phonenumber){
	firstname = _firstname;
	lastname = _lastname;
	phone = _phonenumber;
}

string Phonebook::Contact::toString(){
	return firstname+" "+lastname+" "+phone;
}

Phonebook::Phonebook(){
	count = 0;
	maxSize = 5;
	addresses = new Contact[5];
}

Phonebook::~Phonebook(){
	delete[] addresses;
}

int Phonebook::GetSize(){
	return count;
}

string Phonebook::Find(string firstname, string lastname){
	for(int i = 0; i < count; i++){
		Contact &person = addresses[i];
		if(person.firstname == firstname){
			if(person.lastname == lastname){
				return person.phone;
			}
		}
	}
	return "";
}

void Phonebook::Add(string firstname, string lastname, string phonenumber){
	if(count >= maxSize){
		ExpandArray();
	}
	addresses[count].Set(firstname, lastname, phonenumber);
	count++;
}

void Phonebook::ReadFile(string filename){
	ifstream filestream;
	filestream.open(filename);
	string firstname, lastname, phonenumber;
	while(!filestream.eof()){
		filestream>>firstname>>lastname>>phonenumber;
		Add(firstname, lastname, phonenumber);
	}
	filestream.close();
}

void Phonebook::Delete(string firstname, string lastname){
	bool isFound = false;
	for(int i = 0; i < count; i++)	{
		if(isFound){
			addresses[i-1] = addresses[i];
		}
		else if(addresses[i].firstname == firstname){
			if(addresses[i].lastname == lastname){
				isFound = true;
			}
		}
	}

	if(isFound){
		count--;
	}
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
		cout<<addresses[i]<<endl;
	}
	cout<<"---------------------"<<endl;;
}

std::ostream& operator<<(std::ostream& os, Phonebook& phonebook){
	os << "Phonebook ("<<phonebook.count<<"/"<<phonebook.maxSize<<")";
	return os;
}

