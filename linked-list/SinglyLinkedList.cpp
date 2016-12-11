#include "SinglyLinkedList.h"
// copy constructor
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &object) {
	first = new LinkNode<T>;
	LinkNode<T> *last = first;
	LinkNode<T> *p = object.first->link;
	while(p) {
		LinkNode<T> *newNode = new LinkNode<T>(p->data);
		last->link = newNode;
		last = last->link;
		p = p->link;
	}
}

template<class T> 
SinglyLinkedList<T>::~SinglyLinkedList() {
	LinkNode<T> *p = first;
	while(first->link) {
		p = first->link;
		first->link = p->link;
		delete p;
	}
	delete first;
}

// 1 - length of lsit
template<class T> 
SinglyLinkedList<T>::int Length() const {
	LinkNode<T> *p = first;
	int count = 0;
	while(p) {
		count++;
		p = p->link;
	}
	return count;
}

// 3 - search for a node by value
template<class T> 
SinglyLinkedList<T>::LinkNode<T> *FindItem(const T &item) {
	LinkNode<T> *p = first->link;
	while(p && p->data != item) 
		p = p->link;	
	return p;
}

// 4 - search for a node by index
template<class T> 
SinglyLinkedList<T>::LinkNode<T> *FindLoc(int index) {
	if(index < 0 || index > Length())
		return NULL;
	int i = 0;
	LinkNode<T> *p = first;
	while(p && ++i <= index) // if index is 0 than p will still be first
		p = p->link;	
	return p;
}

template<class T>
SinglyLinkedList<T>::LinkNode<T> *FindLast() {
	LinkNode<T> *p = first;
	while(p->link) 
		p = p->link;
	return p;
}

// 5 - insert a node at a location
template<class T> 
SinglyLinkedList<T>::bool Insert(const T &item, int index) {
	LinkNode<T> *p = FindLoc(index-1);
	if(p) {
		LinkNode<T> *newNode = new LinkNode<T>(item);
		newNode->link = p->link;
		p->link = newNode;
		return true;
	}
	return false;
}

// 6 - insert a node at front
template<class T>
SinglyLinkedList<T>::bool InsertAtFront(const T &item) {
	return Insert(item, 1);
}

// 7 - insert a node at back
template<class T>
SinglyLinkedList<T>::bool InsertAtBack(const T &item) {
	LinkNode<T> *p = FindLast();
	LinkNode<T> *newNode = new LinkNode<T>(item);
	p -> link = newNode;
}

// 8 - delete nodes with given value
template<class T>
SinglyLinkedList<T>::bool RemoveItem(const T &item) {
	// using FinfItem will search twice
	LinkNode<T> *p = first;
	// the advantage of having a first pointer is shown here
	while(p->link && p->link->data != item)
		p = p->link;
	if(p->link) {
		p->link = p->link->link;
		delete p->link;
		return true;
	} 
	return false;
}

// 9 - delete a node with given index
template<class T>
SinglyLinkedList<T>::bool RemoveLoc(int index) {
	LinkNode<T> *p = FindLoc(index-1);
	// the first pointer with no data can not be removed
	if(p) {
		p->link = p->link->link;
		delete p->link;
		return true;
	}
	return false;
}

// 10 - delete first node 
template<class T>
SinglyLinkedList<T>::bool RemoveFront() {
	if(first->link) {
		LinkNode<T> *p = first->link;
		first->link = first->link->link;
		delete p;
		return true;
	}
	return false;
}

// 11 - delete last node
template<class T>
SinglyLinkedList<T>::bool RemoveBack() {
	LinkNode<T> *p = FindLast();
	if(p) {
		delete p;
		return true;
	}
	return false;
}

// 12 - reverse this list
template<class T>
SinglyLinkedList<T>::bool Reverse() {
	LinkNode<T> *p = first->link;
	LinkNode<T> *prev = first;
	LinkNode<T> *aft = p->link;
	if(!p)
		return false;
	
	while(aft) {
		p->link = prev;
		prev = p;
		p = aft;
		aft = aft->link;
	}
	p->link = prev;
	first->link->link = NULL;
	first->link = p;
	return true;
}

// 13 - overload operator <<
template<class T>
ostream& operator<<(ostream &output, const SinglyLinkedList<T> &list) {
	LinkNode<T> *temp = list.first->link;
	if(!temp) {
		std::cout << "The list is empty." << endl;
		return output;
	}
	while(!temp) {
		output << temp->data << "";
		temp = temp->link;
	}
	return output;
}
