#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main3()
{
	string S;
	cin >> S;
	int oneam = 0;
	int zeroam = 0;
	for (int i = 0; i < S.length(); ++i)
	{
		if (S[i] == '1')
		{
			oneam++;
		}
	}
	int j = 0;
	while (j < S.length() && S[j] != '2')
	{
		if (S[j] == '0')
		{
			zeroam++;
		}
		j++;
	}
	for (int i = 0; i < zeroam; ++i)
	{
		cout << '0';
	}
	for (int i = 0; i < oneam; ++i)
	{
		cout << '1';
	}
	while (j < S.length())
	{
		if (S[j] != '1')
		{
			cout << S[j];
		}
		j++;
	}
	return 0;
}