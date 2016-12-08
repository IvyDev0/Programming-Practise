#include "SinglyLinkedList.h"
// copy constructor
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &object) {
	first = new LinkNode<T>;
	LinkNode<T> *last = first;
	LinkNode<T> *p = object.first->link;
	while(p) {
		LinkNode<T> *newNode = new LinkNode<T>(object.first->data);
		last->link = newNode;
		last = last->link;
		p = p->link;
	}
}

SinglyLinkedList<T>::~SinglyLinkedList() {
	LinkNode<T> *p = first;
	while(p->link) {
		p = p->link;
		first->link = p->link;
		delete p;
	}
	if(first)
		first = NULL;
}

// 1 - length of lsit
int Length() const {
	LinkNode<T> *p = first;
	int count = 0;
	while(p) {
		count++;
		p = p->link;
	}
	return count;
}

LinkNode<T> *FindItem(const T &item);// 3 - search for a node by value
LinkNode<T> *FindLoc(int index); // 4 - search for a node by index
bool Insert(const T &item, int index); // 5 - insert a node at a location
bool InsertAtFront(); // 6 - insert a node at front
bool InsertAtBack(); // 7 - insert a node at back
bool RemoveItem(const T &item); // 8 - delete nodes with given value
bool RemoveLoc(int index); // 9 - delete a node with given index
bool RemoveFront(); // 10 - delete first node 
bool RemoveBack(); // 11 - delete last node
bool Reverse(); // 12 - reverse this list
SinglyLinkedList<T>& operator=(const SinglyLinkedList<T> &);  // 13 - overload operator =
