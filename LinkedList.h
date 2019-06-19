#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cstring>
using namespace std;
template<class T>
class LinkedList
{
public:
    class Node
    {
	public:
		T value;
		Node* next;

		Node(T v)
		{
		    value = v;
		    next = nullptr;
		}
	};
private:
    Node* head;
public:
    string delimeter; // optional: just for printing

    LinkedList()
    {
        head = nullptr;
    }

	Node* addSorted(T v)
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


	Node* get(T v)
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

	// operator overloading for printing
	friend ostream& operator<<(ostream& o, LinkedList<T> & c)
	{
	    Node* Current = c.head;
        o << " ";
        while (Current/*->next */!= NULL)
        {
            //o << "";
            o << Current->value << " ";
            Current = Current->next;
        }
        o << endl;
        //o << Current->value << endl;
        return o;
	}
};

#endif // LINKEDLIST_H
