// A Useful Version - Data Structures and Algorithms in C++

#ifndef LINKED_LIST
#define LINKED_LIST 

class Node
{
public:
	int info;
	Node *next;
	Node(int ele, Node *ptr = NULL): info(ele),next(ptr) {}
};



#endif