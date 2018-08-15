#include "stdafx.h"
#include <iostream>
using namespace std;
int main67()
{
	int n, m;
	cin >> n >> m;
	long long maxsum, minsum, x, d;
	maxsum = (long long)n*(n - 1) / 2;
	if (n % 2 == 0)
	{
		minsum = (long long)(n / 2)*(n / 2 - 1) / 2 + (n / 2 + 1)*(n / 2) / 2;
	}
	else
	{
		minsum = (long long)((n - 1) / 2 + 1)*((n - 1) / 2);
	}
	//cout << "minsum = " << minsum << endl;
	long double ans;
	long long sum = 0;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> d;
		sum = sum + x * n;
		if (d > 0)
		{
			sum = sum + d * maxsum;
		}
		else
		{
			sum = sum + d * minsum;
		}
		//cout << "sum = " << sum << endl;
	}
	ans = (long double)sum / n;
	cout.precision(12);
	cout << fixed << ans;
	return 0;
}