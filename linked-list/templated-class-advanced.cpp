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
search for a node (with specific value);
insert a node (with specific value);
delete a node (with specific value, or with a given index);
insert or delete directly at the front or back;

and, operator overload.
*/

template <class T>
struct LinkNode {
	T data;
	LinkNode<T> *link;

	LinkNode(LinkNode<T> *p = NULL) {link = p;}
	LinkNode(const T &item, LinkNode<T> *p = NULL) {
		data = item;
		link = p;
	}
}

template <class T>
class List {
	LinkNode<T> *first;
	LinkNode<T> *getNewNode(const T& = 0, LinkNode<T> * = NULL);
	friend ostream& operator<<<T>(ostream &, const List<T> &);

public:
	List() {first = new LinkNode<T>;}
	List(const T &x) {first = new LinkNode<T>(x);}
	List(const T &x);
	~List();


	int length() const;
	LinkNode<T> *find(int x) {};

	

}