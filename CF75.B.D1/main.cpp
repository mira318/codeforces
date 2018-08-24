#include <iostream>
using namespace std;
const int N = int(1e5) + 7;
long long A[N];
int Ans[N];
long long Mins[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    Mins[n - 1] = A[n - 1];
    for(int i = n - 2; i >= 0; --i)
    {
        Mins[i] = min(Mins[i + 1], A[i]);
        //cout << "Mins[" <<i << "] = " << Mins[i] << endl;
    }
    for(int i = 0; i < n; ++i)
    {
        //cout << "i = " << i << endl;
        int l = i;
        int r = n;
        while(r - l > 1)
        {
            //cout << "r = " << r << endl;
            //cout << "l = " << l << endl;
            int mid = (l + r)/2;
            //cout << "mid = " << mid << endl;
            if(Mins[mid] < A[i])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        if(l == i)
        {
            Ans[i] = -1;
        }
        else
        {
            Ans[i] = l - i - 1;
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << Ans[i] << " ";
    }
    return 0;
}
