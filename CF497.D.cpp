// CF497.D.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
const int N = int(1e5) + 7;
using namespace std;
int Del[3*N];
int Was[N];
int main()
{
	int A, B, C;
	long long ans;
	int predA, predB, predC, size;
	int t;
	cin >> t;
	for (int i = 0; i < N; ++i)
	{
		Was[i] = -1;
	}
	for (int i = 0; i < t; ++i)
	{
		ans = 0;
		predA = 0;
		predB = 0;
		predC = 0;
		size = 0;
		cin >> A >> B >> C;
		for (int j = 1; j*j <= max(max(A, B), C); ++j)
		{
			if(A % j == 0 || B % j == 0 || C % j == 0 && Was[j] != t)
			{
				Del[size] = j;
				size++;
				Was[j] = i;
			}
			if (A % j == 0)
			{
				cout << "Hi" << endl;
				cout << "Was[" << A / j << "] = " << Was[A / j] << endl;
				if (Was[A / j] != i)
				{
					cout << "Hi" << endl;
					Del[size] = A / j;
					size++;
					Was[A / j] = i;
				}
			}
			if (B % j == 0)
			{
				if (Was[B / j] != i)
				{
					Del[size] = B / j;
					size++;
					Was[B / j] = i;
				}
			}
			if (C % j == 0)
			{
				if (Was[C / j] != i)
				{
					Del[size] = C / j;
					size++;
					Was[C / j] = i;
				}
			}
		}
		cout << "done" << endl;
		cout << "size = " << size << endl;
		for(int j = 0; j < size; ++j)
		{
			cout << "j = " << j << endl;
			if (A % Del[j] == 0)
			{
				ans = ans + predB * predC;
			}
			if (B % Del[j] == 0)
			{
				ans = ans + predA * predC;
			}
			if (C % Del[j] == 0)
			{
				ans = ans + predB * predA;
			}
			if (A % Del[j] == 0 && B % Del[j] == 0)
			{
				ans = ans + predC;
			}
			if (A % Del[j] == 0 && C % Del[j] == 0)
			{
				ans = ans + predB;
			}
			if (C % Del[j] == 0 && B % Del[j] == 0)
			{
				ans = ans + predA;
			}
			if (A % Del[j] == 0 && B % Del[j] == 0 && C % Del[j] == 0)
			{
				ans++;
			}
			cout << "ans = " << ans << endl;

			if (A % Del[j] == 0)
			{
				predA++;
			}
			if (B % Del[j] == 0)
			{
				predB++;
			}
			if (C % Del[j] == 0)
			{
				predC++;
			}
		}
		cout << ans;
	}
    return 0;
}

