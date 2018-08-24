#include <iostream>

using namespace std;
const int N = 107;
const int M = 107;
bool Ans[N];
bool Was[N][M];
int Size[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> Size[i];
        int t;
        for(int j = 0; j < Size[i]; ++j)
        {
            cin >> t;
            Was[i][t] = true;
        }
        Ans[i] = true;
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i != j && Size[j] <= Size[i])
            {
                int res = 0;
                for(int t = 1; t <= 100; ++t)
                {
                    if(Was[i][t] && Was[j][t])
                    {
                        res++;
                    }
                }
                if(res == Size[j])
                {
                    Ans[i] = false;
                }
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(Ans[i] == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
