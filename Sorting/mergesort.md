## Mergesort

* Key:

**Divide and conquer**.

* Complexity:

The number of times we can halve n until we get to 1 is log n.

Because the recursion goes log n levels deep, and a linear amount of work is done per level, mergesort takes **O(nlogn)** time in the worst case.

* Code:

```c++
void merge (int * a, int * aux, int lo, int mid, int hi)
{
	// copy
	for (int k = lo; k < hi; k++) aux[k] = a[k];

	// merge, ascending
	int i = lo, j = mid + 1;
	for (int k = lo; k < hi; k++)
	{
		if (i > mid)     			 a[k] = aux[j++];
		else if (j > hi) 			 a[k] = aux[i++];
		else if (aux[i] <= aux[j]) a[k] = aux[i++];
		else 						 a[k] = aux[j++];
	}
}

void sort (int * a, int * aux, int lo, int hi)
{
	if (hi <= lo) return;
	int mid = lo + (hi - lo) / 2;
	sort(a, aux, lo, mid);
	sort(a, aux, mid, hi);
	merge(a, aux, lo, mid, hi);
}

bool MergeSort (int * a)
{
	int * aux = new int[a.length];
	if (aux==NULL)
		return false;
	sort(a, aux, 0, a.length-1);
	delete[] aux;
	return true;
}
```



* Analysis:

Mergesort is a great algorithm for sorting **linked lists**, because it **does not rely on random access to elements** as does heapsort or quicksort. Its primary disadvantage is the need for **an auxilliary buffer** when sorting arrays.
