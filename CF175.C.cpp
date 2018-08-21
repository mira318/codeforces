#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3*int(1e5) + 7;
long long A[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    long long ans = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i + 1 > A[i])
        {
            ans = ans + i + 1 - A[i];
        }
        else
        {
            ans = ans + A[i] - i - 1;
        }
    }
    cout << ans;
    return 0;
}
