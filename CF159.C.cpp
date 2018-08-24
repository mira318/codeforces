#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int N = int(1e5) + 7;
long double X[N];
long double Y[N];
int Chetv[N];
pair<long double, int> All[N];
const long double pi = 3.14159265358979323846;
long double find_yg(int i, int j)
{
    //cout << "find_yg(" << i << ", " << j << ")" << endl;
    long double sc = X[i] * X[j] + Y[i] * Y[j];
    //cout << "sc = " << sc << fixed << endl;
    long double ve = X[i] * Y[j] - X[j] * Y[i];
    //cout << "ve = " << ve << fixed << endl;
    //cout << "give = " << (180*atan2(ve, sc)/pi) << endl;
    if(180*atan2(ve, sc)/pi >= 0)
        return 180*atan2(ve, sc)/pi;
    else
        return 360 + 180*atan2(ve, sc)/pi;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.precision(7);
    int n;
    cin >> n;
    X[0] = 1;
    Y[0] = 1;
    if(n == 1)
    {
        cout << "0.0000000";
        return 0;
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> X[i] >> Y[i];
        long double si = find_yg(i, 0);
        //cout << "si = " << si << endl;
        All[i] = make_pair(si, i);
    }
    long double ans = 360;
    sort(All + 1, All + n + 1);
    for(int i = 2; i <= n; ++i)
    {
        //cout << "i = " << i << endl;
        long double has = find_yg(All[i].second, All[i - 1].second);
        //cout << "has = " << has << endl;
        ans = min(ans, 360 - has);
        //cout << "ans = " << ans << endl;
    }
    long double has = find_yg(All[1].second, All[n].second);
    //cout << "has = " << has << endl;
    ans = min(ans, 360 - has);
    //cout << "ans = " << ans << endl;
    if(ans != 360)
        cout << fixed << ans;
    else
        cout << "0.0000000";
    return 0;
}
