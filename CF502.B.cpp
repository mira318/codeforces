#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int mainB()
{
	int n;
	string A;
	string B;
	long long nullcountA = 0, onecountA = 0, smartnull = 0, smartone = 0;
	cin >> n >> A >> B;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] == '0')
		{
			nullcountA++;
		}
		else
		{
			onecountA++;
		}
	}
	//cout << "nullcountA = " << nullcountA << endl;

	//cout << "onecountA = " << onecountA << endl;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		//cout << "i = " << i << endl;
		if (A[i] == '0' && B[i] == '0')
		{
			ans = ans + onecountA;
			smartnull++;
		}
		if (A[i] == '1' && B[i] == '0')
		{
			ans = ans + nullcountA;
			smartone++;
		}
		//cout << "smartnull = " << smartnull << endl;

		//cout << "smartone = " << smartone << endl;

		//cout << "ans = " << ans << endl;
	}
	ans = ans - smartnull * smartone;
	cout << ans;
	return 0;
}