//#include "stdafx.h"
#include <iostream>
#include <string>
const int N = int(1e5) + 7;
using namespace std;
int Ans[N];
int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "1";
		return 0;
	}
	if (n == 2)
	{
		cout << "1 2";
		return 0;
	}
	if (n == 3)
	{
		cout << "3 1 2";
		return 0;
	}
	if (n == 4)
	{
		cout << "3 4 1 2";
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		Ans[i] = i;
	}
	int j;
	for (int i = 1; i < n; i = i + 2)
	{
		j = Ans[i];
		Ans[i] = Ans[i + 1];
		Ans[i + 1] = j;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << Ans[i] << " ";
	}
	return 0;
}