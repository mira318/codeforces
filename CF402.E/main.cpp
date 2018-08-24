#include <iostream>
#include <map>
using namespace std;
int n;
const int M = 1007;
const int N = 5007;
short Ans1[M];
short Ans2[M];
string Ysl[N];
bool Con[N];
map<string, short> Mor;
int try_it(int razr)
{
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        string P = "";
        int t = 0;
        while(Ysl[i][t] != ':')
        {
            P.push_back(Ysl[i][t]);
            t++;
        }
        if(Con[i] == 0)
        {
            Mor[P] = Ysl[i][t + 3 + razr] - '0';
            if(Mor[P] == 1)
            {
                res++;
            }
        }
        else
        {
            string A = "";
            string B = "";
            t = t + 3;
            while(Ysl[i][t] != ' ')
            {
                A.push_back(Ysl[i][t]);
                t++;
            }
            if(Con[i] == 1 || Con[i] == 2)
            {
                t = t + 5;
                while(t < Ysl[i].length())
                {
                    B.push_back(Ysl[i][t]);
                    t++;
                }
            }
            else
            {
                t = t + 4;
                while(t < Ysl[i].length())
                {
                    B.push_back(Ysl[i][t]);
                    t++;
                }
            }
            short a = Mor[A];
            short b = Mor[B];
            short c;
            if(Con[i] == 1)
            {
                if(a == 1 && b == 1)
                    c = 1;
                else
                    c = 0;
            }
            if(Con[i] == 2)
            {
                if(a != b)
                    c = 1;
                else
                    c = 0;
            }
            if(Con[i] == 3)
            {
                if(a == 1 || b == 1)
                    c = 1;
                else
                    c = 0;
            }
            if(c == 1)
            {
                res++;
            }
            Mor[P] = c;
        }
    }
}
int main()
{
    int m;
    cin >> n >> m;
    string L;
    getline(cin, L);
    for(int i = 0; i < n; ++i)
    {
        getline(cin, Ysl[i]);
        for(int j = 0; j < Ysl[i].length(); ++j)
        {
            if(Ysl[i][j] == 'A')
            {
                Con[i] = 1;
            }
            if(Ysl[i][j] == 'X')
            {
                Con[i] = 2;
            }
            if(Ysl[i][j] == 'O' && Con[i] != 2)
            {
                Con[i] = 3;
            }
        }
    }
    for(int i = 0; i < m; ++i)
    {
        Mor["?"] = 0;
        int res = try_it(i);
        if(res >= n/2)
        {
            Ans2[m] = 0;
        }
        else
        {
            Ans2[m] = 1;
        }
        if(res <= n/2)
        {
            Ans1[m] = 0;
        }
        else
        {
            Ans1[m] = 1;
        }
        Mor.clear();
    }
    for(int i = 0; i < m; ++i)
    {
        cout << Ans1[i];
    }
    cout << endl;
    for(int i = 0; i < m; ++i)
    {
        cout << Ans2[i];
    }
    return 0;
}
