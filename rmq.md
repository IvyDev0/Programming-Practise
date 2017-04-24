## RMQ

Range Maximum(Minimum) Query

* Key:

Preprocess by DP & Query

DP: 

`F(i,j)`: the max(min) of 2^j numbers start form A(i)


$$
F(i,j) = max\{ F(i,2^{j-1}), F(i+2^{j-1},2^{j-1})\}
$$
![RMQ算法 - 天羽 - 天羽的博客](file://localhost/Users/Ivy11D/Library/Group%20Containers/UBF8T346G9.Office/msoclip1/01/08C61F8E-CEDE-4E43-AB11-A363798F22C7.png)



Query:

![RMQ算法 - 天羽 - 天羽的博客](file://localhost/Users/Ivy11D/Library/Group%20Containers/UBF8T346G9.Office/msoclip1/01/3EACD3BB-AFA3-5E40-948B-DA528014B345.png)



* Code:

```c++
int rmq (int * a, int l, int r)
{
	// preprocess
	int n = a.length;
	int m = (int)(log(n)/log(2));
	int (*f)[m] = new int [n][m];
	for (int i = 0; i < n; ++i)
	{
		f[i][0] = a[i];
	}
	for (int j = 1; j < m; ++j)
	{
		for (int i = 1; i < n + 1 - (1<<j); ++i)
		{
			f[i][j] = max(f[i][1<<(j-1)], f[i+(1<<(j-1))][1<<(j-1)]);
		}
	}

	// query
	int x = log(r-l+1) / log(2);
	return max(f[r][x], f[r+1-(1<<x)][r]);
}
```

