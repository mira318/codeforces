#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
const int N3 = 200007;
using namespace std;
long long A2[N3];
map<long long, int> First[11];
int main()
{
	int n, delk = 0;
	long long k;
	cin >> n >> k;
	long long ans;
	for (int i = 1; i < 11; ++i)
	{
		First[i].clear();
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> A2[i];
		cout << "A2[" << i << "] = " << A2[i] << endl;
		if (A2[i] % k == 0)
		{
			delk++;
			cout << "delk = " << delk << endl;
		}
		else
		{
			long long try_it = A2[i];
			for (int j = 1; j < 11; ++j)
			{
				if (First[j].find(try_it % k) == First[j].end())
				{
					First[j][try_it % k] == 1;
				}
				else
				{
					First[j][try_it % k]++;
				}
				try_it = try_it * 10;
			}
		}
	}
	ans = delk*(delk - 1);
	for (int i = 0; i < n; ++i)
	{
		if (A2[i] % k == 0)
		{
			long long st = A2[i];
			for (int j = 1; j < 11; ++j)
			{
				if (k - st % k != st % k)
				{
					if (First[j].find(k - st % k) != First[j].end())
					{
						ans = ans + First[j][k - st % k];
					}
				}
				else
				{
					ans = ans + First[j][k - st % k] * (First[j][k - st % k] - 1);
				}
			}
			
		}
	}
	cout << ans;
	return 0;
}
