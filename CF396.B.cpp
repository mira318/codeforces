#include <iostream>
#include <algorithm>
using namespace std;
const int N = int(1e5) + 7;
long long A[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    for(int i = 2; i < n; ++i)
    {
        //cout << "A[" << i << "]  - A[" << i - 1 << "] = " << A[i] - A[i - 1] << endl;
        if(A[i] - A[i - 1] < A[i - 2])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
