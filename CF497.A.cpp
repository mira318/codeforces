// CF497.A.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.length() - 1; ++i)
	{
		if (S[i] != 'a' && S[i] != 'o' && S[i] != 'e' && S[i] != 'u' && S[i] != 'i' && S[i] != 'n')
		{
			if (S[i + 1] != 'a' && S[i + 1] != 'o' && S[i + 1] != 'e' && S[i + 1] != 'u' && S[i + 1] != 'i')
			{
				cout << "NO";
				return 0;
			}
		}
	}
	if (S[S.length() - 1] != 'n' && S[S.length() - 1] != 'a' && S[S.length() - 1] != 'o' && S[S.length() - 1] != 'e' && S[S.length() - 1] != 'u')
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
    return 0;
}

