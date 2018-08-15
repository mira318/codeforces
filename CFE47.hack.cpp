#include "stdafx.h"
//#include <bits/stdc++.h>
#include <iostream>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int)(n).size())
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll n, m;
ll a[1 << 20], s;

int main() {
	freopen("output.txt", "r", stdin);
	FIN;
	cin >> n >> m;
	fore(i, 0, m) {
		ll x, d, l, r;
		cin >> x >> d;
		s += n*x;
		l = n - 1;
		l = (l*(l + 1)) / 2;
		r = 0;
		if (d<0) {
			int j = n / 2;
			l = j; l = (l*(l + 1)) / 2;
			r = (n - 1 - j); r = r*(r + 1) / 2;
		}
		s += d*(l + r);
	}
	cout.precision(12);
	double ans = s;
	cout << fixed << ans / n << endl;
}