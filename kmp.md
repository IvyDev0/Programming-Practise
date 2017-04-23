## KMP

详解：<http://www.cnblogs.com/yjiyjige/p/3263858.html>





* Code:

```c++
int kmp (char * t, char * p)
{
    int i = 0, j = 0;
    int * next = getNext(p);

    while (i < t.length && j < p.length)
    {
        if (j == -1 || t[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }

    if (j == p.length)
        return i-j; // the head of pattern in string s
    return -1; // not found
}

int getNext (char * p)
{   
    int * next = new int[p.length];
    next[0] = -1;

    int j = 0, k = -1;

    while (j < p.length)
    {
        if (k == -1 || p[j] == p[k])
        {
            if (p[++j] == p[++k])
            {
                next[j] = next[k];
            } 
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
    return next;
}
```

