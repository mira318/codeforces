#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <MAP>
using namespace std;
const int N = int(1e5) + 7;
map< pair <int, int>, int> A;
vector<tuple<int, int, int> > Pice;
int Pice2[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> A[make_pair(i, j)];
        }
    }
    for(int i = 0; i < m; ++i)
    {
        int first = 0;
        int second = 0;
        for(int j = 1; j < n; ++j)
        {
            if(A[make_pair(j, i)] >= A[make_pair(j - 1, i)])
            {
                second++;
            }
            else
            {
                Pice.push_back(make_tuple(first, second, i));
                first = j;
                second = j;
            }
        }
        Pice.push_back(make_tuple(first, second, i));
    }
    sort(Pice.begin(), Pice.end());
    int ind = 0;
    for(int i = 0; i < n; ++i)
    {
        while(get<0>(Pice[ind]) == i)
        {
            ind++;
        }
        if(i == 0)
        {
            Pice2[i] = get<1>(Pice[ind - 1]);
        }
        else
        {
            if(get<1>(Pice[ind - 1]) >= Pice2[i - 1])
            {
                Pice2[i] = get<1>(Pice[ind - 1]);
            }
            else
            {
                Pice2[i] = Pice2[i - 1];
            }
        }
    }
    int k, a, b;
    cin >> k;
    for(int q = 0; q < k; ++q)
    {
        cin >> a >> b;
        a--;
        b--;
        if(Pice2[a] >= b)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
