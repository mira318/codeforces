#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;
    if(S == "0")
    {
        cout << "0";
        return 0;
    }
    int k;
    cin >> k;
    int amo = 0;
    int ans = 0;
    for(int i = S.length() - 1; i >= 0; i--)
    {
        if(amo < k)
        {
            if(S[i] == '0')
            {
                amo++;
            }
            else
            {
                ans++;
            }
        }
    }
    if(amo < k || ans + k == S.length())
    {
        cout << S.length() - 1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
