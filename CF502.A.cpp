#include "stdafx.h"
#include <iostream>
using namespace std;
int mainA()
{
	int n, a, b, c, d;
	cin >> n;
	int ans = 1;
	cin >> a >> b >> c >> d;
	int sum = a + b + c + d;
	int cursum;
	for (int i = 0; i < (n - 1); ++i)
	{
		cin >> a >> b >> c >> d;
		cursum = a + b + c + d;
		if (cursum > sum)
		{
			ans++;
		}
	}
	cout << ans;
    return 0;
}

