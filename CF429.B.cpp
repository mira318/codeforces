#include <iostream>

using namespace std;
const int N = int(1e6) + 7;
long long A[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    bool nch = false;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
        sum = sum + A[i];
        if(A[i] % 2 != 0)
        {
            nch = true;
        }
    }
    if(sum % 2 != 0)
    {
        cout << "First";
        return 0;
    }
    else
    {
        if(!nch)
        {
            cout << "Second";
            return 0;
        }
        else
        {
            cout << "First";
            return 0;
        }
    }
    return 0;
}
