#include "ContactManager.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include "LinkedList.h"
#include "Contact.h"
#include "Treap.h"
using namespace std;

ContactManager::ContactManager()
{
    //ctor
}
bool ContactManager::loadFromFile(string fileName)
{
    string phone , name ;
    ifstream in (fileName.c_str());
    while (!in.eof())
    {
        in >> phone;
        getline(in,name);
        add(name,phone);
    }

    //tree.find(phone);

    //phone = "011";

    //tree.find(phone);
}
void ContactManager::add(string name, string phone_number)
{
   Contact *c = new Contact(name);
   c->addPhoneNumber(phone_number);
   if(contacts.get(*c) == NULL)
   {
     contacts.addSorted(*c);
     tree.insert(phone_number,c);
     //cout << c << " " << &c << " " << *c << endl;
   }
   else
   {
    contacts.get(*c)->value.addPhoneNumber(phone_number);
    tree.insert(phone_number,c);
    //cout << c << " " << &c <<" " << *c << endl;
   }
   //tree.insert(phone_number,c);
}
void ContactManager::displayNumber(string phone_number)
{
    tree.find(phone_number);
}
ostream& operator<<(ostream& o, ContactManager & c)
{
    o << c.contacts;
    return o;
}
ContactManager::~ContactManager()
{
    //dtor
}
