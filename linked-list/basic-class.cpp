// A templated C++ singly linked list

template <class T>

class ListElement {
private:
	T data;
	ListElement *next;

public:
	ListElement(const &T value): next(null), data(value) {}
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
	ListElement(const &T value): next(null), prev(null), data(value) {}
	~ListElement() {}

	T getDate() const {return data;}
	ListElement *getNext() const {return next;}
	ListElement *getPrev() const {return prev;}

	void setData(const T &value) {data = value;}
	void setNext(ListElement *elem) {next = elem;}
	void setPrev(ListElement *elem) {prev = elem;}
};