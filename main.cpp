#include <iostream>
#include "ContactManager.h"
#include "LinkedList.h"
#include "Contact.h"
#include "Treap.h"
using namespace std;

int main()
{
    ContactManager c;
    c.loadFromFile("all-contacts.in");
    cout << "\n\n-------------------Welcome To Contact Manager Application---------------------\n"<<endl;
    cout << "\t\tDisplaying Your Contacts Ordered :\n"<< endl;
    cout << c;
    cout <<endl;
    cout <<"Write The Number You Want To Call :";
    string s;
    cin >> s;
    c.displayNumber(s);

    return 0;
}
