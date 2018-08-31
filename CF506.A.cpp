// CF506.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> Prefix(string S)
{
	//cout << "S = " << S << endl;
	vector<int> Pref;
	Pref.push_back(0);
	//cout << "I am" << endl;
	int k = 0;
	//cout << "Pref[" << 0 << "] = " << Pref[0] << endl;
	for (int i = 1; i < S.length(); ++i)
	{
		while (k > 0 && S[k] != S[i])
		{
			k--;
			k = Pref[k];
		}
		if (S[k] == S[i])
		{
			k++;
		}
		Pref.push_back(k);
		//cout << "Pref[" << i << "] = " << Pref[i] << endl;
	}
	return Pref;

}
int mainA()
{
	int n, k, i;
	cin >> n >> k;
	string T;
	cin >> T;
	vector<int> Res = Prefix(T);
	cout << T;
	for (int i = 0; i < k - 1; ++i)
	{
		for (int j = Res[T.length() - 1]; j < T.length(); ++j)
		{
			cout << T[j];
		}
	}
	return 0;
}
	

