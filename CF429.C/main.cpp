#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 2*int(1e5) + 7;
long long A[M];
long long B[M];
long long Ans[M];
vector<pair<int, int> > My;
int main()
{
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> A[i];
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> B[i];
        My.push_back(make_pair(B[i], i));
    }
    sort(A, A + m);
    sort(My.begin(), My.end());
    int j = 0;
    for(int i = m - 1; i >= 0; --i)
    {
        Ans[My[j].second] = A[i];
        j++;
    }
    for(int i = 0; i < m; ++i)
    {
        cout << Ans[i] << " ";
    }
    return 0;
}
