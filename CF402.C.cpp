#include <iostream>
#include <algorithm>
const int N = 2*int(1e5) + 7;
using namespace std;
int A[N];
int B[N];
pair<int, int> D[N];
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    for(int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }
    for(int i = 0; i < n; ++i)
    {
        D[i] = make_pair(B[i] - A[i], i);
    }
    sort(D, D + n);
    long long sum = 0;
    for(int i = n - 1; i >= n - k; --i)
    {
        //cout << "D[" << i << "].first = " << D[i].first << " " << "D[" << i << "].second = " << D[i].second << endl;
        sum = sum + A[D[i].second];
        //cout << "sum = " << sum << endl;
    }
    int j = n - k - 1;
    while(j >= 0 && D[j].first >= 0)
    {
        //cout << "D[" << j << "].first = " << D[j].first << " " << "D[" << j << "].second = " << D[j].second << endl;
        sum = sum + A[D[j].second];
        //cout << "sum = " << sum << endl;
        j--;
    }
    for(int i = j; i >= 0; --i)
    {
        //cout << "D[" << i << "].first = " << D[i].first << " " << "D[" << i << "].second = " << D[i].second << endl;
        sum = sum + B[D[i].second];
    }
    cout << sum;
    return 0;
}
