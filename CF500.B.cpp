#include "stdafx.h"
#include <iostream>
using namespace std;
int Was[100007];
int Was2[100007];
int A[100007];
int mainB()
{
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < 100007; ++i)
	{
		Was[i] = 0;
		Was2[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		Was[A[i]]++;
		if (Was[A[i]] > 1)
		{
			cout << "0";
			return 0;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int t = A[i] & x;
		//cout << "t = " << t << endl;
		Was2[t]++;
		//cout << "Was[" << t << "] = " << Was[t] << endl;
		if (Was[t] == 1 && A[i] != t)
		{
			cout << "1";
			return 0;
		}
	}
	for (int i = 0; i < 100007; ++i)
	{
		if (Was2[i] > 1)
		{
			cout << "2";
			return 0;
		}
	}
	cout << "-1";
	return 0;
}