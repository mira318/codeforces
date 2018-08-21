#include <iostream>

using namespace std;

int main()
{
    long double Rad, d;
    cin >> Rad >> d;
    int n, ans;
    ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        long double x, y, r;
        cin >> x >> y >> r;
        long long S = x*x + y*y;
        long long S2 = (r + Rad - d) * (r + Rad - d);
        long long S3 = (Rad - r) * (Rad - r);
        if(S >= S2 && S <= S3)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
