## Quick Sort

* Key:


**fill the hole & divide-and-conquer**


* Code:

```c++
void exch(int * a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int * a, int lo, int hi)
{
    int k = lo, i = lo, j = hi;
    while (true)
    {
        while (a[i] <= a[lo])
            if (i == hi) break;

        while (a[j] >= a[lo])
            if (j == lo) break;

        if (i >= j) break;
        exch(a, i, j);
    }

    exch(a, lo, j);
    return j;
}

void sort(int * a, int lo, int hi)
{
    int k = partition(a, lo, hi);
    sort(a, lo, k-1);
    sort(a, k+1, hi);
}

bool QuickSort(int * a)
{
    // shuffle(a); // for performance
    sort(a, 0, a.length - 1);
}
```



* Optimize:

Strategies of choosing the 'base item' x:

Choosing the first or the last item would lead to a worst case when the array is already ordered.

Generating random number would cost more time.

We can choosing the median among the three: l, r, (r-l)/2.
