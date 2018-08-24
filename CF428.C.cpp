#include <iostream>
#include <vector>
using namespace std;
const int N = int(1e5) + 7;
vector <int> Graph[N];
vector <int> Way;
int Len[N];
long double ver[N];
bool Was[N];
int main()
{
    cout.precision(12);
    int n, from, to;
    cin >> n;
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> from >> to;
        from--;
        to--;
        Graph[from].push_back(to);
        Graph[to].push_back(from);
    }
    //for(int t = 0; t < n; ++t)
    //{
        //cout << "Graph[" << t << "]:" << endl;
        //for(int k = 0; k < Graph[t].size(); ++k)
        //{
          //  cout << Graph[t][k] << " ";
        //}
        //cout << endl;
    //}
    for(int i = 1; i < n; ++i)
    {
        Was[i] = false;
    }
    Len[0] = 0;
    ver[0] = 1;
    Way.push_back(0);
    int ind = 0;
    long double ans = 0;
    while(ind < Way.size())
    {
        int v = Way[ind];
        Was[v] = true;
        //cout << "v = " << v << endl;
        //cout << "ver[" << v << "] = " << ver[v] << endl;
        int am = 0;
        for(int j = 0; j < Graph[v].size(); ++j)
        {
            if(!Was[Graph[v][j]])
            {
                am++;
                Len[Graph[v][j]] = Len[v] + 1;
            }
        }
        //cout << "am = "<< am << endl;
        if(am == 0)
        {
            ans = ans + Len[v]*ver[v];
        }
        else
        {
            long double nver = ver[v]/am;
            for(int j = 0; j < Graph[v].size(); ++j)
            {
                if(!Was[Graph[v][j]])
                {
                    ver[Graph[v][j]] = nver;
                    Way.push_back(Graph[v][j]);
                }
            }
        }
        ind++;
    }
    cout << fixed << ans;
    return 0;
}
