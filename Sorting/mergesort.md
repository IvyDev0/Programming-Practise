## Mergesort

* Key: 

**Divide and conquer**.

* Complexity:

The number of times we can halve n until we get to 1 is ⌈lg2 n⌉. 

Because the recursion goes lg n levels deep, and a linear amount of work is done per level, mergesort takes **O(nlogn)** time in the worst case.

* Code:

```c++
void merge (int * a, int first, int mid, int last, int * temp)
{
	int i = first, j = mid+1, k = 0;

	while (i<=mid && j<=last)
	{
		if (a[i]<=a[j]) // select the smaller one 
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	// take all the left
	while (i<=mid) 
		temp[k++] = a[i++];
	while (j<=last) 
		temp[k++] = a[j++];

	// copy the temp array back into a
	for (int i = 0; i < k; ++i)
		a[first+i] = temp[i];
}

void dividesort (int * a, int first, int last, int * temp)
{
	if (first < last)
	{
		int mid = (first + last)/2;
		dividesort (a, first, mid, temp);
		dividesort (a, mid+1, last, temp);
		merge (a, first, mid, last, temp);
	}
}

bool MergeSort (int * a)
{
	int * temp = new int[a.length];
	if (temp==NULL)
		return false;
	dividesort(a, 0, a.length-1, temp);
	delete[] temp;
	return true;
}
```



* Analysis:

Mergesort is a great algorithm for sorting **linked lists**, because it **does not rely on random access to elements** as does heapsort or quicksort. Its primary disadvantage is the need for **an auxilliary buffer** when sorting arrays. 





