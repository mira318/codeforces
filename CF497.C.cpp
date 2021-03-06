// CF497.C.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
const int N = int(1e5) + 7;
long long A[N];

using namespace std;
vector <int> B;

int main()
{
	int n; 
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + n);
	int am = 1;
	int ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if (A[i - 1] == A[i])
		{
			am++;
		}
		else
		{
			B.push_back(am);
			am = 1;
		}
	}
	B.push_back(am);
	int place = B[0];
	for (int i = 1; i < B.size(); ++i)
	{
		if (B[i] <= place)
		{
			place = place - B[i];
			ans = ans + B[i];
		}
		else
		{
			ans = ans + place;
			place = 0;
		}
		place = place + B[i];
	}
	cout << ans;
    return 0;
}

