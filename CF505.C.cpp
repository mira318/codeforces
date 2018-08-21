#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
const int N2 = 100007;
using namespace std;
int Next[N2];
int mainC()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.length() - 1; ++i)
	{
		Next[i] = i + 1;
	}
	Next[S.length() - 1] = 0;
	int maxlen = 0;
	int start = 0;
	bool first_place = false, fall = false, beg = true;
	int cur = start;
	int teklen = 0;
	char pred = '*';
	while (beg || (cur != start && !(fall && first_place)))
	{
		//cout << "cur = " << cur << endl;
		//cout << "fall = " << fall << endl;
		if (beg)
		{
			beg = false;
		}
		else
		{
			if (cur == 0)
			{
				first_place = true;
			}
		}
		//cout << "first_place = " << first_place << endl;
		if (S[cur] != pred)
		{
			teklen++;
			if (fall)
			{
				fall = false;
			}
		}
		else
		{
			fall = true;
			start = cur;
			maxlen = max(teklen, maxlen);
			teklen = 1;
		}
		//cout << "teklen = " << teklen << endl;
		pred = S[cur];
		cur = Next[cur];
	}
	maxlen = max(maxlen, teklen);
	cout << maxlen;
	return 0;
}