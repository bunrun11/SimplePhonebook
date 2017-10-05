#include <iostream>
/*
 * Phonebook.h
 *
 *  Created on: Oct 3, 2017
 *      Author: job
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

class Phonebook{

	struct Contact{
		std::string firstname;
		std::string lastname;
		std::string phone;
		Contact();
		Contact(std::string, std::string, std::string);
		std::string GetName();
		void Set(std::string, std::string, std::string);
		std::string toString();

		friend bool operator==(std::string s, Contact& entry){
			return (s == entry.GetName());
		}

		friend std::ostream& operator<<(std::ostream& os, Contact& entry){
			os << entry.toString();
			return os;
		}
	};

	Contact* addresses;
	int count;
	int maxSize;

	public:
	Phonebook();
	~Phonebook();
	int GetSize();
	std::string Find(std::string, std::string);
	void Add(std::string, std::string, std::string);
	void ReadFile(std::string);
	void Delete(std::string, std::string);
	void ExpandArray();
	void Print();

	friend std::ostream& operator<<(std::ostream&, Phonebook&);
};

#endif /* PHONEBOOK_H_ */
