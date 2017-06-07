struct Node
{
	Node *next;
};
bool Reverse(Node *head)
{
	Node *p = NULL, *t = head;
	
	if (head)
		Node * n = head->next;
	else
		return false;

	while(n)
	{
		t->next = p;

		p = t;
		t = n;
		n = n->next;
	}
	return true;
}