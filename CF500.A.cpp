
#include "stdafx.h"
#include <iostream>
using namespace std;
int mainA()
{
	int n, a, b, sum1 = 0, sum2 = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		sum1 = sum1 + a;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b;
		sum2 = sum2 + b;
	}
	if (sum2 > sum1)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
    return 0;
}

