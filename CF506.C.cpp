#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
const int N2 = 600007;
using namespace std;
vector<pair<long long, pair<char, int>>>All;
int mainC()
{
	int n;
	long long L, R;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> L >> R;
		All.push_back(make_pair(L, make_pair('b', i)));
		All.push_back(make_pair(R, make_pair('e', i)));
	}
	sort(All.begin(), All.end());
	int count = 0;
	long long start, startn;
	int numbern;
	long long maxlen = 0;
	bool check = false;
	bool nlines = false;
	for (int i = 0; i < All.size(); ++i)
	{
		/*cout << "i = " << i << endl;
		cout << "check = " << check << endl;
		cout << "nlines = " << nlines << endl;
		cout << "start = " << start << endl;
		cout << "startn = " << startn << endl;*/
		if (All[i].second.first == 'b')
		{
			count++;
		}
		if (All[i].second.first == 'e')
		{
			if (!nlines)
			{
				if (check)
				{
					//cout << "were there" << endl;
					maxlen = max(maxlen, All[i].first - start);
					check = false;
				}
			}
			else
			{
				if (All[i].second.second == numbern)
				{
					nlines = false;
				}
				else
				{
					maxlen = max(maxlen, All[i].first - start);
					start = startn;
					//cout << "start = " << start << endl;
					nlines = false;
				}
			}
			count--;
		}
		else
		{
			if (count == n - 1)
			{
				start = All[i].first;
				check = true;
			}
			if (count == n)
			{
				nlines = true;
				startn = All[i].first;
				numbern = All[i].second.second;
			}
		}
	}
	cout << maxlen;
	return 0;
}