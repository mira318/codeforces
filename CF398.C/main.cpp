#include <iostream>
#include <vector>
using namespace std;
const int N = int(1e6) + 7;
int P[N];
int T[N];
int Light[N];
vector<int> Graph[N];
void findl(int k)
{
    if(Light[k] == -200)
    {
        if(Graph[k].size() == 0)
        {
            Light[k] = T[k];
        }
        else
        {
            int suml = 0;
            for(int i = 0; i < Graph[k].size(); ++i)
            {
                if(Light[Graph[k][i]] == -200)
                {
                    findl(Graph[k][i]);
                }
                suml = suml + Light[Graph[k][i]];
            }
            Light[k] = suml + T[k];
        }
    }
}
void findl2(int k, int bad)
{
    if(Light[k] == -200 && k != bad)
    {
        if(Graph[k].size() == 0)
        {
            Light[k] = T[k];
        }
        else
        {
            int suml = 0;
            for(int i = 0; i < Graph[k].size(); ++i)
            {
                if(Light[Graph[k][i]] == -200)
                {
                    findl2(Graph[k][i], bad);
                }
                if(Graph[k][i] != bad)
                {
                    suml = suml + Light[Graph[k][i]];
                }
            }
            Light[k] = suml + T[k];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int sumt = 0;
    int root;
    for(int i = 1; i <= n; ++i)
    {
        cin >> P[i];
        if(P[i] == 0)
        {
            root = i;
        }
        else
        {
            Graph[P[i]].push_back(i);
        }
        cin >> T[i];
        sumt = sumt + T[i];
    }
    //cout << "root = " << root << endl;
    if(sumt % 3 != 0)
    {
        cout << "-1";
        return 0;
    }
    int need = sumt/3;
    //cout << "need = " << need << endl;
    for(int i = 1; i <= n; ++i)
    {
        Light[i] = -200;
    }
    //cout << "1:" << endl;
    for(int i = 1; i <= n; ++i)
    {
        findl(i);
        //cout << "Light[" << i << "] = " << Light[i] << endl;
    }
    vector<int> Ans;
    for(int i = 1; i <= n; ++i)
    {
        if(i != root && Light[i] == need)
        {
            Ans.push_back(i);
        }
    }
    if(Ans.size() >= 2)
    {
        cout << Ans[0] << " " << Ans[1];
        return 0;
    }
    if(Ans.size() == 0)
    {
        cout << "-1";
        return 0;
    }
    int v = Ans[0];
    for(int i = 1; i <= n; ++i)
    {
        Light[i] = -200;
    }
    //cout << "2:" << endl;
    for(int i = 1; i <= n; ++i)
    {
        findl2(i, v);
        //cout << "Light[" << i << "] = " << Light[i] << endl;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(i != root && Light[i] == need)
        {
            Ans.push_back(i);
        }
    }
    if(Ans.size() < 2)
    {
        cout << "-1";
        return 0;
    }
    else
    {
        cout << Ans[0] << " " << Ans[1];
    }
    return 0;
}
