#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> Edges;
int NOD(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}
	if (a >= b)
	{
		return NOD(a % b, b);
	}
	else
	{
		return NOD(b % a, a);
	}
}
int main5()
{
	long long  n, m;
	cin >> n >> m;
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	if(m < n - 1 && n*(n - 1) / 2 < m)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		Edges.push_back(make_pair( i + 1, i + 2 ));
	}
	m = m - n + 1;
	//cout << "Edges" << endl;
	//for (int i = 0; i < Edges.size(); ++i)
	//{
		//cout << Edges[i].first << " " << Edges[i].second << endl;
	//}
	//cout << "m = " << m << endl;
	int a, b;
	for (int i = 0; i < n && m > 0; ++i)
	{
		for (int j = i + 2; j < n && m > 0; ++j)
		{
			a = i + 1;
			b = j + 1;
			//cout << "a = " << a << " b = " << b << endl;
			if (NOD(a, b) == 1)
			{
				Edges.push_back(make_pair(a, b));
				m--;
				//cout << "pushed" << endl;
			}
		}
	}
	if (m == 0)
	{
		cout << "Possible" << endl;
		for (int i = 0; i < Edges.size(); ++i)
		{
			cout << Edges[i].first << " " << Edges[i].second << endl;
		}
	}
	else
	{
		cout << "Impossible" << endl;
	}
	return 0;
}