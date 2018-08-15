#include "stdafx.h"
#include <iostream>
#include <algorithm>
const int N = 3007;
using namespace std;
pair<long long, int> I[N];
int Sit[N];
int main()
{
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> I[i].second >> I[i].first;
		ans = ans + I[i].first;
	}
	sort(I, I + n);
	Sit[1] = n;
	for (int i = 2; i <= m; ++i)
	{
		Sit[i] = 0;
	}
	bool good;
	for (int i = n - 1; i >= 0; --i)
	{
		good = true;
		for (int j = 2; j <= m; ++j)
		{
			if (Sit[j] == Sit[1] - 1)
			{
				good = false;
			}
		}
		if (Sit[1] - 1 <= Sit[I[i].second] + 1)
		{
			good = false;
		}
		if (I[i].second == 1)
		{
			good = true;
		}
		if (good)
		{
			Sit[1]--;
			Sit[I[i].second]++;
			ans = ans - I[i].first;
		}
	}
	cout << ans;
	return 0;
}