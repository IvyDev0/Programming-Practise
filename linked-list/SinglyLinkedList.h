/*
Now let's consider the class in a more advanced way, based on the
basic understanding in the basic version.

Now there's a virtual box for singly linked list, you can design 
it's inner structure and patterns by yourself.

So now you know that the real object comes from this virtual box
is a singly linked list. Except the basic put and get of its content
through its ports, what else you want to get from a linked list? and
what changes you want to make to a linked list?

Well, after considering these questions, you can design what the ports
like: given it some inputs as condition, and make it do something you 
want or output something you need. 

Here I want:
know its length;
know whether it's empty;
search for a node (with specific value, or with a given index);
insert a node (with specific value);
delete a node (with specific value, or with a given index);
insert or delete directly at the front or back;
reverse this list;

and, operator overload.
*/

// A templated singly linked list with a begin node

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST


template <class T>
struct LinkNode {
	T data;
	LinkNode<T> *link;

	LinkNode(LinkNode<T> *p = NULL): link(p) {}
	LinkNode(const T &item, LinkNode<T> *p = NULL): data(item),link(p) {}
}

template <class T>
class SinglyLinkedList {
	LinkNode<T> *first;
	friend ostream& operator<<<T>(ostream &, const List<T> &);

public:
	// basic:
	SinglyLinkedList() {first = new LinkNode<T>;} // constructors
	SinglyLinkedList(const T &item) {first = new LinkNode<T>; first->link = new LinkNode<T>(item);}
	SinglyLinkedList(const SinglyLinkedList<T> &); // copy constructor
	~SinglyLinkedList();
	T GetData() {return data;}
	LinkNode<T> *GetNext() {return link;}

	// else:
	int Length() const; // 1 - length of lsit
	bool Isempty() const {return (first->link==NULL)?true:false;}// 2 - whether it's empty
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
}

#endif