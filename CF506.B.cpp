#include "stdafx.h"
#include <iostream>
#include <algorithm>
const int N = 200007;
using namespace std;
long long A[N];
int mainB()
{
	int n;
	cin >> n;
	int count = 0;
	int maxcount = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		if (i != 0)
		{
			if (A[i] > 2 * A[i - 1])
			{
				maxcount = max(count, maxcount);
				count = 1;
			}
			else
			{
				count++;
			}
		}
		else
		{
			count++;
			maxcount = max(count, maxcount);
		}
		//cout << "i = " << i << endl;
		//cout << "count = " << count << endl;
	}
	maxcount = max(count, maxcount);
	cout << maxcount;
	return 0;
}