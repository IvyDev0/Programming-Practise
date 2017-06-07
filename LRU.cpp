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

	// 分离结点
    void detach(Node<K,T>* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    // 将结点插入头部
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

	// TODO:
	void Put (K key, T data);
	T Get (K key);

}