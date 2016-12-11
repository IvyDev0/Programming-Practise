/*
introspection:
The key of class in C++ is wrapper.

Imagine it like a virtual wrapped box in the air, with invisible contents in it and 
some ports on it for you to interact with the box.

Ofcourse you cannot touch it since it's like a virtual scene, so what you want to do 
is to create a real object with its pattern, put things in and get content out.

The most delighted things is that what you have to do is just look at those outside 
ports and use one that can implement exactly what you want, at the mean time keep 
the box's inner structure.

That is the basic, basic, basic idea of what class is like.
*/

// A templated C++ singly linked list

template <class T>
class ListElement {
private:
	T data;
	ListElement *next;

public:
	ListElement(const &T value): data(value),next(null) {}
	~ListElement() {}

	T getDate() const {return data;}
	ListElement *getNext() const {return next;}

	void setData(const T &value) {data = value;}
	void setNext(ListElement *elem) {next = elem;}
};

// A templated C++ doubly linked list

template <class T>
class ListElement {
private:
	T data;
	ListElement *next;
	ListElement *prev;

public:
	ListElement(const &T value): data(value), next(null), prev(null) {}
	~ListElement() {}

	T getDate() const {return data;}
	ListElement *getNext() const {return next;}
	ListElement *getPrev() const {return prev;}

	void setData(const T &value) {data = value;}
	void setNext(ListElement *elem) {next = elem;}
	void setPrev(ListElement *elem) {prev = elem;}
};




