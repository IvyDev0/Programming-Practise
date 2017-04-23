## Quick Sort

* Key: 


**fill the hole & divide-and-conquer **



* Steps:



* Code:

```c++
void quicksort(int a[], int l, int r)
{
    if(l<r)
    {
        int i = l, j = r, x = a[i];
        while(i<j)
        {
            while(i<j && a[j]>=x) // find a[j]<x, take it as a hole
                --j;
            if(i<j)
                a[i++] = a[j]; // fill this hole with finded item

            while(i<j && a[i]<=x) // find a[i]>x
                ++i;
            if(i<j)
                a[j--] = a[i]; // fill the hole 
        }
        a[i] = x; 
      	// result: all items in front of x are smaller than x,
     	// all items behind x are bigger than x.
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
    }
}
```



* Optimize:

Strategies of choosing the 'base item' x:

Choosing the first or the last item would lead to a worst case when the array is already ordered.

Generating random number would cost more time.

We can choosing the median among the three: l, r, (r-l)/2.



