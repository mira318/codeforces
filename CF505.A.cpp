// CF505.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
int Was[27];
int mainA()
{
	int n;
	string S;
	cin >> n;
	cin >> S;
	for (int i = 0; i < 26; ++i)
	{
		Was[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		Was[S[i] - 'a']++;
		//cout << "Was[" << S[i] - 'a' << "] = " << Was[S[i] - 'a'] << endl;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (Was[i] > 1)
		{
			cout << "Yes";
			return 0;
		}
	}
	if (n != 1)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
    return 0;
}

