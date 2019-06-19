#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <cstring>
#include "LinkedList.h"

using namespace std;

class Contact
{
private:
    string name;
	LinkedList<string> phone_numbers;
public:
    Contact();
    Contact(string name);
	void addPhoneNumber(string number);
	string getName();
	bool operator<(const Contact & c);
	bool operator==(const Contact & c);
	friend ostream& operator<<(ostream& o, Contact & c);
    virtual ~Contact();
};
#endif // CONTACT_H
