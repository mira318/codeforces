#include <iostream>

using namespace std;
const int N = int(1e3) + 7;
const long long M = 1e9 + 7;
int A[27];
bool Was[27];
int Can[N];
long long Ans[N];

int main()
{
    int n;
    cin >> n;
    string S;
    cin >> S;
    for(int i = 0; i < 26; ++i)
    {
        cin >> A[i];
    }
    int ans = 0;
    for(int i = 0; i < S.length(); ++i)
    {
        //cout << "i = " << i << endl;
        int l_now = 0;
        bool flag = true;
        int j = 0;
        while(flag && i + j < S.length())
        {
            //cout << "j = " << j << endl;
            Was[S[i + j] - 'a'] = true;
            l_now++;
            //cout << "l_now = " << l_now << endl;
            for(int j = 0; j < 26; ++j)
            {
                if(Was[S[i + j] - 'a'] && A[S[i + j] - 'a'] < l_now)
                {
                    flag = false;
                }
            }
            j++;
        }
        ans = max(ans, l_now - 1);
        //cout << "ans = " << ans << endl;
        if(!flag)
        {
            Can[i] = l_now - 1;
        }
        else
        {
            Can[i] = l_now;
        }
        for(int j = 0; j < 26; ++j)
        {
            Was[j] = false;
        }
        //cout << "Can[" << i << "] = " << Can[i] << endl;
    }
    for(int i = 0; i < Can[0]; ++i)
    {
        Ans[i] = 1;
    }
    for(int i = 1; i < n; ++i)
    {
        //cout << "i = " << i << endl;
        for(int j = 1; j <= i; ++j)
        {
            //cout << "j = " << j << endl;
            if(Can[j] >= i - j + 1)
            {
                //cout << "Can["<< j << "] = " << Can[j] << endl;
                Ans[i] = (Ans[i] + Ans[j - 1])%M;
                //cout << "Ans[" << i << "] = " << Ans[i] << endl;
            }
        }
    }
    for(int i = 0; i < 26; ++i)
    {
        Was[i] = false;
    }
    int l_now2 = 0;
    int ans2 = 1;
    for(int i = 0; i < S.length(); ++i)
    {
        //cout << "i = " << i << endl;
        bool flag2 = true;
        for(int j = 0; j < 6; ++j)
        {
            //cout << "l_now2 = " << l_now2 << endl;
            //cout << "A[" << j << "] = " << A[j] << endl;
            //cout << "Was[" << j << "] = " << Was[j] << endl;
            if(Was[j] && (A[j] < (l_now2 + 1)))
            {
                flag2 = false;
            }
        }
        //cout << "l_now2 = " << l_now2 << endl;
        //cout << "A[" << S[i] - 'a' << "] = " << A[S[i] - 'a'] << endl;
        //cout << "flag2 = " << flag2 << endl;
        if(!flag2 || (A[S[i] - 'a'] < (l_now2 + 1)))
        {
            ans2++;
            l_now2 = 1;
            for(int j = 0; j < 26; ++j)
            {
                Was[j] = false;
            }
            Was[S[i] - 'a'] = true;
        }
        else
        {
            l_now2++;
            Was[S[i] - 'a'] = true;
            //cout << "Was[" << S[i] - 'a' << "] = " << Was[S[i] - 'a'] << endl;
        }
    }
    cout << Ans[n - 1] <<endl << ans << endl << ans2;
    return 0;
}
