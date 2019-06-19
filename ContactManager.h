#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include "LinkedList.h"
#include "Contact.h"
#include "Treap.h"  // for Task 2
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class ContactManager
{
private:
    LinkedList<Contact> contacts;
	Treap<string, Contact*> tree; // for Task 2
public:
    ContactManager();
    bool loadFromFile(string fileName);
	void add(string name, string phone_number);
	void displayNumber(string phone_number);
	friend ostream& operator<<(ostream& o, ContactManager & c);
    virtual ~ContactManager();

};

#endif // CONTACTMANAGER_H
