//#include "stdafx.h"
#include <iostream>
using namespace std;
const int N = 1007;
long double A2[N];
long double B2[N];
int n;
long double m;
bool check(long double am)
{
	//cout << "check(" << am << ")" << endl;
	long double weight = am + m;
	//cout << "weight = " << weight << endl;
	weight = weight - (long double)weight / A2[0];
	if (weight < m)
	{
		return false;
	}
	//cout << "weight = " << weight << endl;
	for (int i = 1; i < n; ++i)
	{
		
		//cout << "B2[" << i << "] = " << B2[i] << endl;
		//cout << "A2[" << i << "] = " << A2[i] << endl;

		weight = weight - (long double)(weight / B2[i]);
		//cout << "weight = " << weight << endl;
		if (weight < m)
		{

			//cout << "false" << endl;
			return false;
		}
		weight = weight - (long double)(weight / A2[i]);
		//cout << "weight = " << weight << endl;
		if (weight < m)
		{

			//cout << "false" << endl;
			return false;
		}
	}
	weight = weight - (long double)(weight / B2[0]);
	//cout << "weight = " << weight << endl;
	if (weight < m)
	{
		//cout << "false" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> A2[i] >> B2[i];
		if (A2[i] == 1 || B2[i] == 1)
		{
			cout << "-1";
			return 0;
		}
		//cout << "A2[" << i << "] = " << A2[i] << endl;

		//cout << "B2[" << i << "] = " << B2[i] << endl;
	}
	long double left = 0, right = 1000000001;
	while (right - left >= 0.00000001)
	{
		long double mid = (left + right) / 2;
		if (check(mid))
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}
	//if (right > 1000000001)
	//{
		//cout << "-1";
		//return 0;
	//}
	cout.precision(12);
	cout << fixed << right;
	return 0;
}
