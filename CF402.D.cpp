#include <iostream>

using namespace std;
const int N = 2*int(1e5) + 7;
int A[N];
string T, P;
bool check(int a)
{
    string S = T;
    for(int i = 0; i < a; ++i)
    {
        S[A[i] - 1] = '*';
    }
    int j = 0;
    for(int i = 0; i < S.length(); ++i)
    {
        if(S[i] == P[j] && j < P.length())
        {
            j++;
        }
    }
    if(j == P.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cin >> T >> P;
    for(int i = 0; i < T.length(); ++i)
    {
        cin >> A[i];
    }
    int l = 0;
    int r = T.length();
    while(r - l > 1)
    {
        int mid = (r + l)/2;
        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l;
    return 0;
}
