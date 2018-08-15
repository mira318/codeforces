#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
int B[107];
int Amount[123];
int mainB()
{
	int n, m;
	cin >> n >> m;
	if (n > m)
	{
		cout << "0";
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}
	sort(B, B + m);
	for (int i = 1; i <= B[m - 1]; ++i)
		Amount[i] = 0;
	for (int i = 0; i < m; ++i)
	{
		Amount[B[i]]++;
	}
	//for (int i = 0; i < m; ++i)
	//{
		//cout << "Amount[" << B[i] << "] = " << Amount[B[i]] << endl;
	//}
	bool flag = true;
	int i, done;
	for (i = 1; i <= m && flag == true; i++)
	{
		//cout << "i = " << i << endl;
		done = 0;
		for (int j = 1; j <= B[m - 1]; ++j)
		{
			//cout << "Amount[" << j << "] = " << Amount[j] << endl;
			done = done + Amount[j] / i;
		}
		//cout << "done = " << done << endl;
		if (done < n)
		{
			cout << i - 1;
			return 0;
		}
	}
	cout << i - 1;
	return 0;
}