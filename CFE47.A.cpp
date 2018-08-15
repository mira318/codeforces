#include "stdafx.h"
#include <iostream>
const int N = 10007;
int A[N];
int C[N];
using namespace std;
int main2()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> C[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> A[i];
	}
	int i = 0, j = 0, ans = 0;
	while (j < n && i < m)
	{
		if (A[i] >= C[j])
		{
			i++;
			ans++;
		}
		j++;
	}
	cout << ans;
    return 0;
}

