/*#include "LinkedList.h"
#include <iostream>
#include <cstring>
using namespace std;

LinkedList::LinkedList()
{
    head = Null;
}

Node* LinkedList::addSorted(T v)
{
    Node * n = new Node(v);

    if (head == NULL)
    {
        head = n ;
        return n;
    }
    else if (n->value < head->value)
    {
        n->next = head ;
        head = n;
        return n;
    }

    Node * temp1 = head , * temp2 = NULL;
    while (temp1->value < n->value)
    {
        temp2 = temp1;
        temp1 = temp1->next ;
        if(temp1 == NULL)
        {
            temp2->next = n;
            return n ;
        }
    }
    temp2->next = n;
    n->next = temp1;
    return n ;
}

Node* LinkedList::get(T v)
{
    Node * temp = head;

    if(temp == NULL)
        return NULL;

    while (temp->value.getName() != v.getName())
    {
        temp = temp->next;
        if(temp == NULL)
            return NULL;
    }

    return temp;
}
template<class T>
ostream& operator<<(ostream& o, LinkedList<T> & c)
{
    Node* Current = c.head;
    o << "-";
    while (Current/*->next != NULL)
    {
        o << Current->value << " ";
        Current = Current->next;
    }
    //o << Current->value << endl;
    return o;
}
*/
