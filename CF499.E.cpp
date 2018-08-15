#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 100007;
bool Prost[M];
int Nam[M];
vector<int> ProCh;
vector<int> Ans;
bool Can[M];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= k; ++i)
	{
		Prost[i] = true;
	}
	for (int i = 2; i <= k; ++i)
	{
		if (Prost[i])
		{
			for (int j = 2; j*i <= k; ++j)
			{
				Prost[i*j] = false;
			}
			ProCh.push_back(i);
		}
	}
	cout << "ProCH" << endl;
	for (int i = 0; i < ProCh.size(); ++i)
	{
		cout << ProCh[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> Nam[i];
		Nam[i] = Nam[i] % k;
		cout << "Nam[" << i << "] = " << Nam[i] << endl;
	}
	sort(Nam, Nam + n);
	int cur;
	for (int i = 0; i < ProCh.size(); ++i)
	{
		cur = ProCh[i];
		for (int j = n - 1; j >= 0; --j)
		{
			while(cur >= Nam[j])
			{
				cur = cur - Nam[j];
			}
		}
		if (cur == 0)
		{
			Can[i] = true;
		}
		else
		{
			Can[i] = false;
		}
		cout << "Can[" << i << "] = " << Can[i] << endl;
	}
	bool divide;
	for (int i = 1; i <= k; ++i)
	{
		divide = false;
		for (int j = 0; j < ProCh.size(); ++j)
		{
			if (i % ProCh[j] == 0 && Can[j])
			{
				divide = true;
			}
		}
		if (divide)
		{
			Ans.push_back(i);
		}
	}
	cout << Ans.size();
	for (int i = 0; i < Ans.size(); ++i)
	{
		cout << Ans[i] << " ";
	}
	return 0;
}