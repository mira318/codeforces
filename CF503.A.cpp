
#include "stdafx.h"
#include <iostream>
using namespace std;
int mainA()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;
	int f1, f2, t1, t2, ans;
	for (int i = 0; i < k; ++i)
	{
		ans = 0;
		cin >> t1 >> f1 >> t2 >> f2;
		if(t1 != t2)
		{
			if (f1 < a)
			{
				ans = ans + a - f1;
				f1 = a;
			}
			if (f1 > b)
			{
				ans = ans + f1 - b;
				f1 = b;
			}
		}
		ans = ans + abs(t2 - t1);
		ans = ans + abs(f1 - f2);
		cout << ans << endl;
	}
    return 0;
}

