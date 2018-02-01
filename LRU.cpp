template<class K, class T>
struct Node
{
	K type;
	T data;
	Node *prev, *next;
}

template<class K, class T>
class LRUcache
{
	hash_map<K, Node<K,T>*> hashmap;
	vector<Node<K,T>*> free_entries;
	Node<K,T> *tail, *head;
	Node<K,T> *entries;

    void detach(Node<K,T>* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    // insert node after head
    void attach(Node<K,T>* node)
    {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }

public:
	LRUcache(size_t size)
	{
		entries = new Node<K,T> [size];
		for (int i = 0; i < size; ++i)
		{
			free_entries.push_back(entries+i);
		}
		head = new Node<K,T>;
		tail = new Node<K,T>;
		head->prev = NULL;
		head->next = tail;
		tail->prev = head;
		tail->next = NULL;
	}
	~LRUcache()
	{
		delete head;
		delete tail;
		delete[] entries;
	}

	void Set (K key, T data) // Cache visit Mem and get data
	{
		Node<K,T> *node = hashmap[key];
		if (node) // key exist in cache
		{
			detach(node);
			node->data = data;
			attach(node);
		}
		else
		{
			if (free_entries.empty()) // no free, cache is full
			{
				node = tail->prev;
				detach(node);
				hashmap.erase(node->key); // delete the last node in cache
			}
			else
			{	// free space --
				node = free_entries.back();
				free_entries.popback();
			}
			// set the new value
			node->key = key;
			node->data = data;
			attach(node);
			hashmap[key] = node;
		}
	}

	T Get (K key) // ALU visit Cache, return data
	{
		Node<K,T> *node = hashmap[key];
		if (node)
		{
			detach(node);
			attach(node); // put node to the first
			return node->data;
		}
		else
		{
			return T();  // 66666
		}
	}
}
