#include <iostream>
#include <algorithm>
using namespace std;
const long double pi = 3.141592653589793;
long double R[107];
int main()
{
    int n;
    cin >> n;
    long double S = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> R[i];
    }
    sort(R, R + n);
    for(int i = n - 1; i >= 0; --i)
    {
        if((n - 1 - i) % 2 == 0)
        {
            S = S + pi*R[i]*R[i];
        }
        else
        {
            S = S - pi*R[i]*R[i];
        }
    }
    cout.precision(14);
    cout << S << fixed;
    return 0;
}
