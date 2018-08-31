#include <iostream>

using namespace std;
bool Was[28];
int main()
{
    string A, B;
    cin >> A >> B;
    int j = 0;
    int ans = -1;
    for(int i = 0; i < A.length(); ++i)
    {
        if(j < B.length() && A[i] == B[j])
        {
            j++;
        }
    }
    if(j < B.length())
    {
        int l = B.length();
        ans = max(ans, l);
    }
    j = 0;
    for(int i = 0; i < B.length(); ++i)
    {
        if(j < A.length() && B[i] == A[j])
        {
            j++;
        }
    }
    if(j < A.length())
    {
        int l = A.length();
        ans = max(ans, l);
    }
    cout << ans;
    return 0;
}
