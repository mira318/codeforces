#include <iostream>
#include <vector>
using namespace std;
const int N = 2*int(1e5) + 7;
int A[N];
int Ans[N];
int Nod_with[N];
int Nod[N];
bool Was[N];
vector<int> Graph[N];
int NOD(int a, int b)
{
    while(a != 0 && b != 0)
    {
        if(a >= b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if(a != 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void dfs(int w)
{
    Was[w] = true;
    //cout << "dfs " << w << endl;
    for(int i = 0; i < Graph[w].size(); ++i)
    {
        int u = Graph[w][i];
        if(!Was[u])
        {
            Nod[u] = NOD(Nod[w], A[u]);
            //cout << "Nod[" << u << "] = " << Nod[u] << endl;
            Nod_with[u] = max(NOD(Nod_with[w], A[u]), Nod[w]);
            //cout << "Nod_with[" << u << "] = " << Nod_with[u] << endl;
            Ans[u] = max(Nod[u], Nod_with[u]);
            //cout << "Ans[" << u << "] = " << Ans[u] << endl;
            dfs(u);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    int c, d;
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> c >> d;
        c--;
        d--;
        Graph[c].push_back(d);
        Graph[d].push_back(c);
    }
    Ans[0] = A[0];
    Was[0] = true;
    for(int i = 0; i < Graph[0].size(); ++i)
    {
        int v = Graph[0][i];
        Nod[v] = NOD(A[0], A[v]);
        Nod_with[v] = max(A[0], A[v]);
        Ans[v] = max(Nod_with[v], Nod[v]);
        dfs(v);
    }
    for(int i = 0; i < n; ++i)
    {
        cout << Ans[i] << " ";
    }
    return 0;
}
