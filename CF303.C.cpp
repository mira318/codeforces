#include <iostream>

using namespace std;
const int N = int(1e5) + 7;
pair <long long, long long> Tree[N];
pair<int, long long> DP[N];
int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> Tree[i].first >> Tree[i].second;
    }
    DP[0].first = 1;
    DP[0].second = Tree[0].first;
    for(int i = 1; i < n - 1; ++i)
    {
        DP[i].first = DP[i - 1].first;
        DP[i].second = Tree[i].first;
        if(Tree[i].first - Tree[i].second > Tree[i - 1].first)
        {
            int l = -1;
            int r = i;
            while(r - l > 1)
            {
                int mid = (r + l)/2;
                if(DP[mid].second >= Tree[i].first - Tree[i].second)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            if(DP[l].first + 1 > DP[i].first)
            {
                DP[i].first = DP[l].first + 1;
                DP[i].second = Tree[i].first;
            }
        }
        if(Tree[i].first + Tree[i].second < Tree[i + 1].first)
        {
            if(DP[i].first < DP[i - 1].first + 1)
            {
                DP[i].first = DP[i - 1].first + 1;
                DP[i].second = Tree[i].first + Tree[i].second;
            }
        }
    }
    cout << DP[n - 2].first + 1;
    return 0;
}
