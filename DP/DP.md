## DP

#### Store the solution

* Fibonacci - O(n)

```c++
int fib (int n, map<int, int> myMap)
{
	if (n == 1 || n == 0)
		return 1;
	// look up in map first
	map<int, int>::iterator iter = myMap.find(n);
	if (iter == myMap.end())
	{
		int result = fib(n-1, myMap) + fib(n-2 result, myMap);
		myMap.insert(pair<int, int>(n, result));
		return result;
	}
	else
		return iter->second;
}
```

* Minimum Distance - O(n)

```C++
int MinDistance (int v)
{
	if (minPath[v] > 0) // check the record first
		return minPath[v];
	if (v==N-1) // boundary
		return 0;

	int t, path;
	// MinDis(v) = min{w(v,u) + MinDis(u)}
	for (int i = v+1; i < N; ++i)
	{
		if (matrix[v][i] > 0)
		{
			t = matrix[v][i] + MinDistance(i);
			if (t < min)
			{
				min = t; // select the min
				path = i;
			}
		}
	}

	minPath[v] = min;
	trace[v] = path;
	return min;
}
```

