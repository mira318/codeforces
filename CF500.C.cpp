#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
const int  N = 100007;
long long A[N];
int n;
bool check1(int mid)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] > mid)
		{
			count++;
		}
	}
	if (count > n)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool check2(int mid)
{

}
int main()
{
	cin >> n;
	for (int i = 0; i < 2 * n; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + 2 * n);
	long long max1 = A[2 * n - 1], max2 = A[2 * n - 2], min1 = A[0], min2 = A[1];
	long long left = min1, right = max1 + 1;
	long long minx, miny;
	while (right - left > 1)
	{
		long long mid = (right + left) / 2;
		if (check1(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	minx = right - min1;
	long long left = min1, right = max1 + 1;
	while (right - left > 1)
	{
		long long mid = (right + left) / 2;
		if (check2(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	minx = min(minx, max1 - left);
	long long left = min1, right = max1 + 1;
	while (right - left > 1)
	{
		long long mid = (right + left) / 2;
		if (check3(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	long long left = min1, right = max1 + 1;
	while (right - left > 1)
	{
		long long mid = (right + left) / 2;
		if (check4(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}

	return 0;
}