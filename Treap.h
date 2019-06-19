#ifndef TREAP_H
#define TREAP_H
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include "ContactManager.h"
#include "LinkedList.h"
#include "Contact.h"
using namespace std;

template<class T, class V>
class Treap {
public:
	class Node {
	public:
		Node *left, *right;
		T key;
		V value;
		int priority;

		Node(T k, V v)
		{
		    key = k;
		    value = v;
		    left = right = NULL ;
		    priority = rand()% 500;
		}
		friend ostream& operator<<(ostream &o, Treap<T, V>::Node root);
	};
private:
	Node* root;

	Node* rotateRight(Node* Q)
	{
	    Node *temp = Q->left, *temp2 = temp->right;
        temp->right = Q;
        Q->left = temp2;
        return temp;
	}

	Node* rotateLeft(Node* P)
	{
	    Node *temp = P->right, *temp2 = temp->left;
        temp->left = P;
        P->right = temp2;
        return temp;
	}
	//Node* balance(Node* root);
	Node* insert(Node* root, T k, V v)
	{
	    Node* n =  new Node(k,v);

        if (root == NULL)
        {
            this->root = n ;
            return n;
        }
        if (k > root->key)
        {
            root->right = insert(root->right, k, v);

            if (root->right->priority > root->priority)
                root = rotateLeft(root);
        }

        else
        {
            root->left = insert(root->left, k, v);

            if (root->left->priority > root->priority)
                root = rotateRight(root);
        }
        //cout << root << " " << endl;
        return root;
	}

	V find(Node* root, T k)
	{
	    if (root == NULL)
        {
            cout << k << " : " << k <<endl;
            return NULL;
        }

        if (root->key == k)
        {
            cout << k << " : " ;
            cout << root->value->getName()<<endl;
            return root->value;
        }

        if (root->key < k)
            return find(root->right, k);
        else
            return find(root->left, k);
	}

ostream& print(ostream &o, Node* root)
{
    if (root != NULL)
    {
        o << root->key << " ";
        print(root->left);
        print(root->right);
    }
    return o;
}
public:
	Treap()
	{
	    root = NULL;
	}
	void insert(T k, V v)
	{
	    root = insert(root, k, v);
	    //insert(root,k,v);
	}

	V find(T k)
	{
	    return find(root,k);
	}

	friend ostream& operator<<(ostream &o, Treap<T, V> tree)
	{
	    o = print(tree.root,o);
        return o;
	}
};

#endif // TREAP_H

