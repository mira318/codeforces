#include "stdafx.h"
/*#include <iostream>
const int N = 1007;
using namespace std;
int P[N];
bool Was[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> P[i];
	}
	bool flag;
	int cur;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			Was[j] = false;
		}
		flag = false;
		cur = i;
		while (!flag)
		{
			if (Was[cur])
			{
				flag = true;
			}
			else
			{
				Was[cur] = true;
				cur = P[cur];
			}
		}
		cout << cur << " ";
	}
	return 0;
}*/