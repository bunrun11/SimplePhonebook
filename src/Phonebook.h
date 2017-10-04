#include <string>
#include <sstream>
/*
 * Phonebook.h
 *
 *  Created on: Oct 3, 2017
 *      Author: jobbe_000
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

class Phonebook{

	struct Contact{
		std::string firstname;
		std::string lastname;
		std::string phone;
		Contact();
		Contact(std::string);
		std::string GetName();
		void Set(std::string);
		std::string toString();
		bool operator==(Contact);
		//std::ostream& operator<<(std::ostream& os, const Contact&);
	};

	Contact* addresses;
	int count;
	int maxSize;

	public:
	Phonebook();
	Phonebook(std::string[], int);
	~Phonebook();
	int GetSize();
	std::string Find(std::string);
	void Add(std::string);
	void ReadFile(std::string);
	void Delete(std::string);
	void ExpandArray();
	void Print();
};

#endif /* PHONEBOOK_H_ */
