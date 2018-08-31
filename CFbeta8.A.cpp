#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    int minb = A.length() + 1;
    for(int i = 0; i + B.length() <= A.length(); ++i)
    {
        //cout << "i = " << i << endl;
        int res = 0;
        for(int j = 0; j < B.length(); ++j)
        {
            //cout << "j = " << j << endl;
            if(A[i + j] == B[j])
            {
                res++;
            }
            //cout << "res = " << res << endl;
        }
        if(res == B.length())
        {
            int l = B.length();
            minb = min(minb, i + l - 1);
            //cout << "minb = " << minb << endl;
        }
    }
    int minc = A.length() + 1;
    for(int i = minb + 1; i + C.length() <= A.length(); ++i)
    {
        //cout << "i = " << i << endl;
        int res = 0;
        for(int j = 0; j < C.length(); ++j)
        {
            //cout << "j = " << j << endl;
            if(A[i + j] == C[j])
            {
                res++;
            }
            //cout << "res = " << res << endl;
        }
        if(res == C.length())
        {
            int l = C.length();
            minc = min(minc, i + l - 1);
            //cout << "minc = " << minc << endl;
        }
    }
    bool to = false;
    bool from = false;
    if(minc < A.length())
    {
        to = true;
    }
    //cout << "to = " << to << endl;
    int maxb = -1;
    //cout << "B.length() - 1 = " << B.length() - 1 << endl;
    int l = B.length();
    for(int i = A.length() - 1; i >= (l - 1); --i)
    {
        //cout << "i = " << i << endl;
        int res = 0;
        for(int j = 0; j < B.length(); ++j)
        {
            //cout << "j = " << j << endl;
            if(A[i - j] == B[j])
            {
                res++;
            }
            //cout << "res = " << res << endl;
        }
        if(res == B.length())
        {
            int l2 = B.length();
            maxb = max(maxb, i - l2 + 1);
            //cout << "maxb = " << maxb << endl;
        }
    }
    int maxc = -1;
    l = C.length();
    for(int i = maxb - 1; i >= l - 1; --i)
    {
        int res = 0;
        for(int j = 0; j < C.length(); ++j)
        {
            if(A[i - j] == C[j])
            {
                res++;
            }
        }
        if(res == C.length())
        {
            int l2 = C.length();
            maxc = max(maxc, i - l2 + 1);
        }
    }
    //cout << "maxc = " << maxc << endl;
    if(maxc >= 0)
    {
        from = true;
    }
    if(from && to)
    {
        cout << "both";
        return 0;
    }
    if(to)
    {
        cout << "forward";
        return 0;
    }
    if(from)
    {
        cout << "backward";
        return 0;
    }
    cout << "fantasy";
    return 0;
}
