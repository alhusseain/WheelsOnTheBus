#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	Node<T> *Tail;	
public:


	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}
	

	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}
	
	void InsertEnd(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
	}


	void Insert(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		Node<T> *P = Head;
		Node<T> *Q = nullptr;
		while(P && P->getItem() < data)
		{
			Q = P;
			P = P->getNext();
		}
		if(Q == nullptr)
		{
			Head = R;
		}
		else
		{
			Q->setNext(R);
		}
		R->setNext(P);
	}

	
	bool Find(const T &x)
	{
		Node<T> *p = Head;

		while(p)
		{
			if (p->getItem() == x){
			cout << "Found!";
			p = false;
			return true;
		} else {
			p = p->getNext();
			return false;
		}
	}

	}


	void DeleteFirst()
	{
		Node<T> *P = Head;
		P = Head->getNext();
		delete Head;
		Head = P;
	}

	void DeleteLast()
	{
		Node<T> *P = Head;
		while(Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}
	
	void DeleteNode(const T &x) {
    Node<T> *p = Head;
    Node<T> *q = nullptr;

    while (p != nullptr) {
        if (p->getItem() == x) {
            if (q == nullptr) {
                // If the node to be deleted is the head node
                Head = p->getNext();
            } else {
                q->setNext(p->getNext());
            }

            Node<T> *temp = p;
            p = p->getNext(); // Move p to the next node
            delete temp;      // Delete the node
        } else {
            q = p;
            p = p->getNext();
        }
    }
}

	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}

	int getLength()
	{
		Node<T> *p = Head;
		int count = 0;
		while(p)
		{
			count++;
			p = p->getNext();
		}
		return count;
	}

		void PrintList()	const
	{
		Node<T> *p = Head;
		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << " , ";
			p = p->getNext();
		}
		cout << "\n";
	}

};

#endif	
