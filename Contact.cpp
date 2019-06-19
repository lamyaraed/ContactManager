#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;
Contact::Contact()
{
    name = "";
}
Contact::Contact(string name)
{
    this->name = name;
}
void Contact::addPhoneNumber(string number)
{
    phone_numbers.addSorted(number);
}
string Contact::getName()
{
    return name;
}
bool Contact::operator<(const Contact & c)
{
    return ( name.compare(c.name) < 0 );
}
bool Contact::operator==(const Contact & c)
{
    return ( name.compare(c.name) == 0 );
}
ostream& operator<<(ostream& o, Contact & c)
{
    o << c.name << " : "<< c.phone_numbers ;
     return o;
}
Contact::~Contact()
{

}
