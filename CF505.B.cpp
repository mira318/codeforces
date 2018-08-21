//#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
const int N = 150007;
using namespace std;
unsigned long int A[N];
unsigned long int B[N];
unsigned long int NOK[N];
unsigned long int NOD(unsigned long int a, unsigned long int b)
{
	if (a == 0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}
	if (a > b)
	{
		a = a % b;
		return NOD(a, b);
	}
	else
	{
		b = b % a;
		return NOD(a, b);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i] >> B[i];
		NOK[i] = (A[i] * B[i]) / NOD(A[i], B[i]);
	}
	unsigned long int wholeNOD = NOK[0];
	if (n == 1)
	{
		cout << A[0];
		return 0;
	}
	for (int i = 1; i < n; ++i)
	{
		wholeNOD = NOD(wholeNOD, NOK[i]);
	}
	if (wholeNOD == 1)
	{
		cout << "-1";
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			wholeNOD = max(NOD(wholeNOD, A[i]), NOD(wholeNOD, B[i]));
		}
		cout << wholeNOD;
	}
	return 0;
}