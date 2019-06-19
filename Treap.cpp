/*#include "Treap.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "ContactManager.h"
#include "LinkedList.h"
#include "Contact.h"
using namespace std;

Node* Treap::rotateRight(Node* Q)
{
    Node *temp = Q->left, *temp2 = temp->right;
    temp->right = Q;
    Q->left = temp2;
    return temp;
}

Node* Treap::rotateLeft(Node* P)
{
    Node *temp = P->right, *temp2 = temp->left;
    temp->left = P;
    P->right = temp2;
    return temp;
}
Node* Treap::insert(Node* root, T k, V v)
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
    return root;
}

V Treap::find(Node* root, T k)
{
    if (root == NULL)
    {
        cout << k << " : " ;
        cout << k <<endl;
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
Treap::Treap()
{
    root = NULL;
}

void Treap::insert(T k, V v)
{
    insert(root,k,v);
}
V Treap::find(T k)
{
    return find(root,k);
}
ostream& operator<<(ostream &o, Treap<T, V> tree)
{
    o = print(tree.root,o);
    return o;
}
*/
