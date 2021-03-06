// CF497.B.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
const int N = int(1e5) + 7;
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long a, b, max = 1000000001;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (a > max && b > max)
		{
			cout << "NO";
			return 0;
		}
		if (a >= b)
		{
			if (a <= max)
			{
				max = a;
			}
			else
			{
				max = b;
			}
		}
		else
		{
			if (b <= max)
			{
				max = b;
			}
			else
			{
				max = a;
			}
		}
	}
	cout << "YES";
    return 0;
}

