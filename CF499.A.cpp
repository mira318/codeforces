// CF499.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int A[100];
int mainA()
{
	int n, k;
	char c;
	cin >> n >> k;
	if (k > n)
	{
		cout << "-1";
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> c;
		A[i] = c - 'a' + 1;
	}
	sort(A, A + n);
	int i = 0;
	int ans = 0;
	int prev = 0;
	while (k > 0 && i < n)
	{
		//cout << "A[" << i << "] = " << A[i] << endl;

		ans = ans + A[i];
		//cout << "ans = " << ans << endl;
		k--;
		//cout << "k = " << k << endl;
		prev = A[i];
		//cout << "prev = " << prev << endl;
		i++;
		while (i < n && A[i] <= prev + 1)
		{
			i++;
		}
		//cout << "i = " << i << endl;
	}
	if (k == 0)
	{
		cout << ans;
	}
	else
	{
		cout << "-1";
	}
    return 0;
}

